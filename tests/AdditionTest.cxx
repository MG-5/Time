#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Addition, operatorPlusMinutes1)
{
    Time time("11:30");

    Time result = time + 25;

    EXPECT_EQ(result.hour, 11);
    EXPECT_EQ(result.minute, 55);
}

TEST(Addition, operatorPlusMinutes2)
{
    Time time("11:30");

    Time result = time + 56;

    EXPECT_EQ(result.hour, 12);
    EXPECT_EQ(result.minute, 26);
}

TEST(Addition, operatorPlusMinutes3)
{
    Time time("11:30");

    Time result = time + 275;

    EXPECT_EQ(result.hour, 16);
    EXPECT_EQ(result.minute, 05);
}

TEST(Addition, operatorPlusMinutes4)
{
    Time time("11:30");

    Time result = time + (-25);

    EXPECT_EQ(result.hour, 11);
    EXPECT_EQ(result.minute, 05);
}

TEST(Addition, operatorPlusMinutes5)
{
    Time time("23:45");

    Time result = time + 30;

    EXPECT_EQ(result.hour, 0);
    EXPECT_EQ(result.minute, 15);
}

TEST(Addition, operatorPlusMinutes6)
{
    Time time("23:45");

    Time result = time + 95;

    EXPECT_EQ(result.hour, 1);
    EXPECT_EQ(result.minute, 20);
}

TEST(Addition, operatorPlusMinutes7)
{
    Time time("01:30");

    Time result = time + (24 * 60);

    EXPECT_EQ(time, result);
}

TEST(Addition, operatorPlusTime1)
{
    Time time("01:22");
    Time duration("8:30");

    Time result = time + duration;

    EXPECT_EQ(result.hour, 9);
    EXPECT_EQ(result.minute, 52);
}

TEST(Addition, operatorPlusTime2)
{
    Time time("01:22");
    Time duration("01:58");

    Time result = time + duration;

    EXPECT_EQ(result.hour, 03);
    EXPECT_EQ(result.minute, 20);
}

TEST(Addition, operatorPlusTime3)
{
    Time time("23:47");
    Time duration("02:22");

    Time result = time + duration;

    EXPECT_EQ(result.hour, 2);
    EXPECT_EQ(result.minute, 9);
}

TEST(Addition, operatorPlusSeconds1)
{
    Time time("23:47");
    EXPECT_EQ(time.second, 0);

    Time duration(0, 0, 20);
    Time result = time + duration;

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 47);
    EXPECT_EQ(result.second, 20);
}

TEST(Addition, operatorPlusSeconds2)
{
    Time time("23:47");
    EXPECT_EQ(time.second, 0);

    Time duration(0, 0, 65);
    EXPECT_EQ(duration.minute, 1);
    EXPECT_EQ(duration.second, 5);
    Time result = time + duration;

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 48);
    EXPECT_EQ(result.second, 5);
}

TEST(Addition, operatorPlusSeconds3)
{
    Time time("23:47");
    EXPECT_EQ(time.second, 0);

    Time duration(0, 0, 1200);
    Time result = time + duration;

    EXPECT_EQ(result.hour, 0);
    EXPECT_EQ(result.minute, 7);
    EXPECT_EQ(result.second, 0);
}

TEST(Addition, addHours1)
{
    Time time("22:00");

    time.addHours(1);

    EXPECT_EQ(time.hour, 23);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 0);
}

TEST(Addition, addHours2)
{
    Time time("22:00");

    time.addHours(2);

    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 0);
}

TEST(Addition, addMinutes1)
{
    Time time("22:00");

    time.addMinutes(20);

    EXPECT_EQ(time.hour, 22);
    EXPECT_EQ(time.minute, 20);
    EXPECT_EQ(time.second, 0);
}

TEST(Addition, addMinutes2)
{
    Time time("22:00");

    time.addMinutes(65);

    EXPECT_EQ(time.hour, 23);
    EXPECT_EQ(time.minute, 5);
    EXPECT_EQ(time.second, 0);
}

TEST(Addition, addMinutes3)
{
    Time time("22:00");

    time.addMinutes(130);

    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 10);
    EXPECT_EQ(time.second, 0);
}

TEST(Addition, addSeconds1)
{
    Time time("22:00");
    EXPECT_EQ(time.second, 0);

    time.addSeconds(10);

    EXPECT_EQ(time.hour, 22);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 10);
}

TEST(Addition, addSeconds2)
{
    Time time("22:00");
    EXPECT_EQ(time.second, 0);

    time.addSeconds(65);

    EXPECT_EQ(time.hour, 22);
    EXPECT_EQ(time.minute, 1);
    EXPECT_EQ(time.second, 5);
}

TEST(Addition, addSeconds3)
{
    Time time("23:47");
    EXPECT_EQ(time.second, 0);

    time.addSeconds(1200);

    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 7);
    EXPECT_EQ(time.second, 0);
}