#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class Time
{
public:
    Time() = default;
    Time(const std::string &timeAsString);
    Time(size_t newHour, size_t newMinute = 0, size_t newSecond = 0);
    Time(const Time &other) // copy-constructor
    {
        this->hour = other.hour;
        this->minute = other.minute;
        this->second = other.second;
    }

    ~Time() = default;

    Time operator+(const Time &otherTime) const;
    Time operator+(const size_t numberOfMinutes) const;

    Time operator-(const Time &otherTime) const;
    Time operator-(const size_t numberOfMinutes) const;

    Time &operator=(const Time &other);

    void addHours(const size_t numberOfHours);
    void addMinutes(const size_t numberOfMinutes);
    void addSeconds(const size_t numberOfSeconds);

    friend std::ostream &operator<<(std::ostream &os, const Time &time);
    friend bool operator==(const Time &lhTime, const Time &rhTime);
    friend bool operator<(const Time &lhTime, const Time &rhTime);

    [[nodiscard]] uint16_t getMinutes() const;
    [[nodiscard]] uint32_t getSeconds() const;

    static uint16_t getDifferenceInMinutes(const Time &time, const Time &otherTime);

    uint8_t hour = 0;
    uint8_t minute = 0;
    uint8_t second = 0;

private:
    Time subtractHelper(int diffHours, int diffMinutes, int diffSeconds) const;
};
