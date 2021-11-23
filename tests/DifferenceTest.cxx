#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Difference, getMinutes1)
{
    Time time("11:30");

    EXPECT_EQ(time.getMinutes(), (11 * 60) + 30);
}

TEST(Difference, getMinutes2)
{
    Time time("23:58");

    EXPECT_EQ(time.getMinutes(), (23 * 60) + 58);
}

TEST(Difference, getMinutes3)
{
    Time time("00:01");

    EXPECT_EQ(time.getMinutes(), 1);
}

TEST(Difference, difference1)
{
    Time time1("11:30");
    Time time2("12:15");

    auto result = Time::getDifferenceInMinutes(time1, time2);
    EXPECT_EQ(result, 45);
}

TEST(Difference, difference2)
{
    Time time1("11:30");
    Time time2("15:45");

    auto result = Time::getDifferenceInMinutes(time1, time2);
    EXPECT_EQ(result, 255);
}

TEST(Difference, difference3)
{
    Time time1("11:30");
    Time time2("11:30");

    auto result = Time::getDifferenceInMinutes(time1, time2);
    EXPECT_EQ(result, 0);
}

TEST(Difference, difference4)
{
    Time time1("11:30");
    Time time2("11:45");

    auto result = Time::getDifferenceInMinutes(time1, time2);
    EXPECT_EQ(result, 15);
}

TEST(Difference, difference5)
{
    Time time1("11:30");
    Time time2("11:00");

    EXPECT_DEATH(Time::getDifferenceInMinutes(time1, time2), "");
}

TEST(Difference, difference6)
{
    Time time1("11:30");
    Time time2("10:30");

    EXPECT_DEATH(Time::getDifferenceInMinutes(time1, time2), "");
}