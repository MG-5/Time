#include "Time.hpp"

#include <cassert>
#include <cmath>
#include <iomanip>

//--------------------------------------------------------------------------------------------------
Time::Time(const std::string &timeAsString)
{
    auto pos = timeAsString.find(':');

    assert(pos != std::string::npos);

    hour = std::stoi(timeAsString.substr(0, pos));
    minute = std::stoi(timeAsString.substr(pos + 1));

    *this = Time(hour, minute);
}

//--------------------------------------------------------------------------------------------------
Time::Time(const uint8_t newHour, const uint8_t newMinute, const uint8_t newSecond)
{
    second = newSecond;
    if (second > 60)
    {
        minute = second / 60;
        second %= 60;
    }

    minute += newMinute;
    if (minute > 59)
    {
        hour += minute / 60;
        minute %= 60;
    }

    hour += newHour;
    hour %= 24;
}

//--------------------------------------------------------------------------------------------------
Time Time::operator+(Time &otherTime) const
{
    return *this + otherTime.getMinutes();
}

//--------------------------------------------------------------------------------------------------
Time Time::operator+(int numberOfMinutes) const
{
    return *this - (-numberOfMinutes);
}

//--------------------------------------------------------------------------------------------------
Time Time::operator-(Time &otherTime) const
{
    return *this - otherTime.getMinutes();
}

//--------------------------------------------------------------------------------------------------
Time Time::operator-(int numberOfMinutes) const
{
    int tempHour = hour - (numberOfMinutes / 60);
    int tempMinutes = minute - numberOfMinutes % 60;

    uint8_t newHour;
    uint8_t newMinutes;

    // this is needed due %-modulo operator doesn't calc negative numbers correctly in this case
    if (tempMinutes < 0)
    {
        tempHour -= (tempMinutes / 60 + 1);
        newMinutes = (60 + tempMinutes);
    }
    else
    {
        tempHour += tempMinutes / 60;
        newMinutes = tempMinutes;
    }

    newHour = tempHour;

    if (tempHour < 0)
        newHour += 24;

    newHour %= 24;
    newMinutes %= 60;

    return {newHour, newMinutes};
}

//--------------------------------------------------------------------------------------------------
Time &Time::operator=(const Time &other)
{
    if (this != &other)
    {
        this->hour = other.hour;
        this->minute = other.minute;
    }
    return *this;
}

//--------------------------------------------------------------------------------------------------
bool operator==(const Time &lhTime, const Time &rhTime)
{
    return lhTime.hour == rhTime.hour && lhTime.minute == rhTime.minute;
}

//--------------------------------------------------------------------------------------------------
bool operator<(const Time &lhTime, const Time &rhTime)
{
    return lhTime.hour < rhTime.hour ||
           (lhTime.hour == rhTime.hour && lhTime.minute < rhTime.minute);
}

//--------------------------------------------------------------------------------------------------
[[nodiscard]] uint16_t Time::getMinutes() const
{
    return minute + hour * 60;
}

//--------------------------------------------------------------------------------------------------
uint16_t Time::getDifferenceInMinutes(const Time &time, const Time &otherTime)
{
    if (time.hour <= otherTime.hour &&
        (time.hour != otherTime.hour || time.minute <= otherTime.minute))
        return (otherTime - time.getMinutes()).getMinutes();

    else
        return (24 * 60) - time.getMinutes() + otherTime.getMinutes();
}

//--------------------------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Time &time)
{
    os << std::setfill('0') << std::setw(2) << int(time.hour);
    os << ':';
    os << std::setfill('0') << std::setw(2) << int(time.minute);
    os << ':';
    os << std::setfill('0') << std::setw(2) << int(time.second);
    return os;
}
