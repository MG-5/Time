#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(SmallerThanOperator, smallerThan1)
{
    Time time1("11:30");
    Time time2("12:30");

    EXPECT_TRUE(time1 < time2);
}

TEST(SmallerThanOperator, smallerThan2)
{
    Time time1("11:30");
    Time time2("12:00");

    EXPECT_TRUE(time1 < time2);
}

TEST(SmallerThanOperator, smallerThan3)
{
    Time time1("11:30");
    Time time2("11:40");

    EXPECT_TRUE(time1 < time2);
}

TEST(SmallerThanOperator, smallerThan4)
{
    Time time1("11:40");
    Time time2("11:30");

    EXPECT_FALSE(time1 < time2);
}

TEST(SmallerThanOperator, smallerThan5)
{
    Time time1("11:40");
    Time time2("10:40");

    EXPECT_FALSE(time1 < time2);
}