#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Constructor, Constructor1)
{
    Time time("11:30");

    EXPECT_EQ(time.hour, 11);
    EXPECT_EQ(time.minute, 30);
}

TEST(Constructor, constructor2)
{
    Time time("26:05");

    EXPECT_EQ(time.hour, 2);
    EXPECT_EQ(time.minute, 05);
}

TEST(Constructor, constructor3)
{
    Time time("04:75");

    EXPECT_EQ(time.hour, 5);
    EXPECT_EQ(time.minute, 15);
}

TEST(Constructor, constructor4)
{
    Time time(11, 30);

    EXPECT_EQ(time.hour, 11);
    EXPECT_EQ(time.minute, 30);
}

TEST(Constructor, constructor5)
{
    Time time(26, 05);

    EXPECT_EQ(time.hour, 2);
    EXPECT_EQ(time.minute, 05);
}

TEST(Constructor, constructor6)
{
    Time time(04, 75);

    EXPECT_EQ(time.hour, 5);
    EXPECT_EQ(time.minute, 15);
}

TEST(Constructor, constructor7)
{
    EXPECT_DEATH(Time time("0123"), "");
}

TEST(Constructor, constructor8)
{
    Time time;

    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 0);
}