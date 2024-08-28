#include "Time.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

//--------------------------------------------------------------------------------------------------
Time::Time(const std::string &timeAsString)
{
    if (timeAsString.find_first_not_of("0123456789:") != std::string::npos)
        return;

    // count the number of colons in the string
    const auto NumberOfColons = std::count(timeAsString.begin(), timeAsString.end(), ':');

    switch (NumberOfColons)
    {
        case 1: // hh:mm
        {
            auto pos = timeAsString.find(':');
            auto tempHour = std::stoi(timeAsString.substr(0, pos));
            auto tempMinute = std::stoi(timeAsString.substr(pos + 1));
            *this = Time(tempHour, tempMinute);
        }
        break;

        case 2: // hh:mm:ss
        {
            auto pos = timeAsString.find(':');
            auto tempHour = atoi(timeAsString.substr(0, pos).c_str());
            auto pos2 = timeAsString.find(':', pos + 1);
            auto tempMinute = atoi(timeAsString.substr(pos + 1, pos2 - pos - 1).c_str());
            auto tempSecond = atoi(timeAsString.substr(pos2 + 1).c_str());
            *this = Time(tempHour, tempMinute, tempSecond);
        }
        break;

        default:
            break;
    }
}

//--------------------------------------------------------------------------------------------------
Time::Time(const size_t newHour, const size_t newMinute, const size_t newSecond)
{
    second = newSecond % 60;
    const auto TempMinutes = newMinute + newSecond / 60;
    minute = TempMinutes % 60;
    hour = (newHour + TempMinutes / 60) % 24;
}

//--------------------------------------------------------------------------------------------------
Time Time::operator+(const Time &otherTime) const
{
    return Time(this->hour + otherTime.hour,     //
                this->minute + otherTime.minute, //
                this->second + otherTime.second);
}

//--------------------------------------------------------------------------------------------------
Time Time::operator+(const size_t numberOfMinutes) const
{
    return Time(this->hour,                     //
                this->minute + numberOfMinutes, //
                this->second);
}

//--------------------------------------------------------------------------------------------------
Time Time::operator-(const Time &otherTime) const
{
    return subtractHelper(otherTime.hour,   //
                          otherTime.minute, //
                          otherTime.second);
}

//--------------------------------------------------------------------------------------------------
Time Time::operator-(const size_t numberOfMinutes) const
{
    return subtractHelper(0, numberOfMinutes, 0);
}

//--------------------------------------------------------------------------------------------------
Time Time::subtractHelper(int diffHours, int diffMinutes, int diffSeconds) const
{
    diffMinutes += diffSeconds / 60;
    diffSeconds %= 60;

    uint8_t newSecond;
    if (second < diffSeconds)
    {
        newSecond = 60 - (diffSeconds - second);
        diffMinutes++;
    }
    else
        newSecond = second - diffSeconds;

    diffHours += diffMinutes / 60;
    diffMinutes %= 60;
    uint8_t newMinute;

    if (minute < diffMinutes)
    {
        newMinute = 60 - (diffMinutes - minute);
        diffHours++;
    }
    else
        newMinute = minute - diffMinutes;

    diffHours %= 24;
    uint8_t newHour;

    if (hour < diffHours)
        newHour = 24 - (diffHours - hour);
    else
        newHour = hour - diffHours;

    return Time(newHour, newMinute, newSecond);
}

//--------------------------------------------------------------------------------------------------
void Time::addHours(const size_t numberOfHours)
{
    hour = (hour + numberOfHours) % 24;
}

//--------------------------------------------------------------------------------------------------
void Time::addMinutes(const size_t numberOfMinutes)
{
    const auto HoursToAdd = (numberOfMinutes + minute) / 60;
    addHours(HoursToAdd);
    minute = (numberOfMinutes + minute) % 60;
}

//--------------------------------------------------------------------------------------------------
void Time::addSeconds(const size_t numberOfSeconds)
{
    const auto MinutesToAdd = (numberOfSeconds + second) / 60;
    addMinutes(MinutesToAdd);
    second = (numberOfSeconds + second) % 60;
}

//--------------------------------------------------------------------------------------------------
void Time::subHours(const size_t numberOfHours)
{
    *this = *this - numberOfHours * 60;
}

//--------------------------------------------------------------------------------------------------
void Time::subMinutes(const size_t numberOfMinutes)
{
    *this = *this - numberOfMinutes;
}

//--------------------------------------------------------------------------------------------------
Time &Time::operator=(const Time &other)
{
    if (this != &other)
    {
        this->hour = other.hour;
        this->minute = other.minute;
        this->second = other.second;
    }
    return *this;
}

//--------------------------------------------------------------------------------------------------
bool operator==(const Time &lhTime, const Time &rhTime)
{
    return lhTime.hour == rhTime.hour && lhTime.minute == rhTime.minute &&
           lhTime.second == rhTime.second;
}

//--------------------------------------------------------------------------------------------------
bool operator<(const Time &lhTime, const Time &rhTime)
{
    return lhTime.hour < rhTime.hour ||
           (lhTime.hour == rhTime.hour &&
            (lhTime.minute < rhTime.minute ||
             (lhTime.minute == rhTime.minute && lhTime.second < rhTime.second)));
}

//--------------------------------------------------------------------------------------------------
uint16_t Time::getMinutes() const
{
    return minute + hour * 60;
}

//--------------------------------------------------------------------------------------------------
uint32_t Time::getSeconds() const
{
    return second + getMinutes() * 60;
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
