#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class Time
{
public:
    Time() = default;
    Time(const std::string &timeAsString);
    Time(uint8_t newHour, uint8_t newMinute = 0, uint8_t newSecond = 0);
    Time(const Time &other) // copy-constructor
    {
        this->hour = other.hour;
        this->minute = other.minute;
        this->second = other.second;
    }

    ~Time() = default;

    Time operator+(Time &otherTime) const;
    Time operator+(int numberOfMinutes) const;

    Time operator-(Time &otherTime) const;
    Time operator-(int numberOfMinutes) const;

    Time &operator=(const Time &other);

    friend std::ostream &operator<<(std::ostream &os, const Time &time);
    friend bool operator==(const Time &lhTime, const Time &rhTime);
    friend bool operator<(const Time &lhTime, const Time &rhTime);

    [[nodiscard]] uint16_t getMinutes() const;
    [[nodiscard]] uint32_t getSeconds() const;

    static uint16_t getDifferenceInMinutes(const Time &time, const Time &otherTime);

    uint8_t hour = 0;
    uint8_t minute = 0;
    uint8_t second = 0;
};
