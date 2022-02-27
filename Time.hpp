#pragma once

#include <iostream>
#include <string>

class Time
{
public:
    Time() = default;
    Time(const std::string &timeAsString);
    Time(uint8_t newHour, uint8_t newMinute);
    ~Time() = default;

    Time operator+(Time &otherTime) const;
    Time operator+(int numberOfMinutes) const;

    Time operator-(Time &otherTime) const;
    Time operator-(int numberOfMinutes) const;

    Time &operator=(const Time &other);

    friend std::ostream &operator<<(std::ostream &os, const Time &time);
    friend bool operator==(const Time &lhTime, const Time &rhTime);

    [[nodiscard]] uint16_t getMinutes() const;

    static uint16_t getDifferenceInMinutes(const Time &time, const Time &otherTime);

    uint8_t hour = 0;
    uint8_t minute = 0;
};
