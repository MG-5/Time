#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Subtraction, subtraction1)
{
    Time time("11:30");

    Time result = time - 25;

    EXPECT_EQ(result.hour, 11);
    EXPECT_EQ(result.minute, 05);
}

TEST(Subtraction, subtraction2)
{
    Time time("11:30");

    Time result = time - 56;

    EXPECT_EQ(result.hour, 10);
    EXPECT_EQ(result.minute, 34);
}

TEST(Subtraction, subtraction3)
{
    Time time("11:30");

    Time result = time - 275;

    EXPECT_EQ(result.hour, 06);
    EXPECT_EQ(result.minute, 55);
}

TEST(Subtraction, subtraction4)
{
    Time time("00:15");

    Time result = time - 30;

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 45);
}

TEST(Subtraction, subtraction5)
{
    Time time("01:20");

    Time result = time - 95;

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 45);
}

TEST(Subtraction, subtraction6)
{
    Time time("01:30");

    Time result = time - (24 * 60);

    EXPECT_EQ(time, result);
}

TEST(Subtraction, subtraction7)
{
    Time time("09:52");
    Time duration("8:30");

    Time result = time - duration;

    EXPECT_EQ(result.hour, 1);
    EXPECT_EQ(result.minute, 22);
}

TEST(Subtraction, subtraction8)
{
    Time time("03:20");
    Time duration("01:58");

    Time result = time - duration;

    EXPECT_EQ(result.hour, 01);
    EXPECT_EQ(result.minute, 22);
}

TEST(Subtraction, subtraction9)
{
    Time time("02:09");
    Time duration("02:22");

    Time result = time - duration;

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 47);
}

TEST(Subtraction, subtraction10)
{
    Time time("02:00");
    Time duration(0, 0, 50);

    Time result = time - duration;

    EXPECT_EQ(result.hour, 1);
    EXPECT_EQ(result.minute, 59);
    EXPECT_EQ(result.second, 10);
}

TEST(Subtraction, subtraction110)
{
    Time time("00:07");
    Time duration(0, 0, 1200);

    Time result = time - duration;

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 47);
    EXPECT_EQ(result.second, 0);
}
