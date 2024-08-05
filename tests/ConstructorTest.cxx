#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Constructor, Constructor1)
{
    Time time("11:30");

    EXPECT_EQ(time.hour, 11);
    EXPECT_EQ(time.minute, 30);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor2)
{
    Time time("26:05");

    EXPECT_EQ(time.hour, 2);
    EXPECT_EQ(time.minute, 05);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor3)
{
    Time time("04:75");

    EXPECT_EQ(time.hour, 5);
    EXPECT_EQ(time.minute, 15);
    EXPECT_EQ(time.second, 0);
}

TEST(TimeConstructor, constructor4)
{
    Time time("11:30:45");
    EXPECT_EQ(time.hour, 11);
    EXPECT_EQ(time.minute, 30);
    EXPECT_EQ(time.second, 45);
}

TEST(TimeConstructor, invalidFormat)
{
    Time time("11:30:45:60");
    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 0);
}

TEST(TimeConstructor, invalidFormat2)
{
    Time time("1130");
    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 0);
}

TEST(TimeConstructor, invalidFormat3)
{
    Time time("ab:cd");
    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor5)
{
    Time time(11, 30);

    EXPECT_EQ(time.hour, 11);
    EXPECT_EQ(time.minute, 30);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor6)
{
    Time time(26, 05);

    EXPECT_EQ(time.hour, 2);
    EXPECT_EQ(time.minute, 05);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor7)
{
    Time time(04, 75);

    EXPECT_EQ(time.hour, 5);
    EXPECT_EQ(time.minute, 15);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor8)
{
    Time time;

    EXPECT_EQ(time.hour, 0);
    EXPECT_EQ(time.minute, 0);
    EXPECT_EQ(time.second, 0);
}

TEST(Constructor, constructor9)
{
    Time time(04, 25, 30);

    EXPECT_EQ(time.hour, 4);
    EXPECT_EQ(time.minute, 25);
    EXPECT_EQ(time.second, 30);
}

TEST(Constructor, constructor10)
{
    Time time(04, 25, 65);

    EXPECT_EQ(time.hour, 4);
    EXPECT_EQ(time.minute, 26);
    EXPECT_EQ(time.second, 05);
}

TEST(Constructor, constructor11)
{
    Time time(04, 25, 125);

    EXPECT_EQ(time.hour, 4);
    EXPECT_EQ(time.minute, 27);
    EXPECT_EQ(time.second, 05);
}