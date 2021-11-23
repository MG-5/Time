#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Addition, addition1)
{
    Time time("11:30");

    Time result = time + 25;

    EXPECT_EQ(result.hour, 11);
    EXPECT_EQ(result.minute, 55);
}

TEST(Addition, addition2)
{
    Time time("11:30");

    Time result = time + 56;

    EXPECT_EQ(result.hour, 12);
    EXPECT_EQ(result.minute, 26);
}

TEST(Addition, addition3)
{
    Time time("11:30");

    Time result = time + 275;

    EXPECT_EQ(result.hour, 16);
    EXPECT_EQ(result.minute, 05);
}

TEST(Addition, addition4)
{
    Time time("11:30");

    Time result = time + (-25);

    EXPECT_EQ(result.hour, 11);
    EXPECT_EQ(result.minute, 05);
}

TEST(Addition, addition5)
{
    Time time("11:30");

    Time result = time + (-56);

    EXPECT_EQ(result.hour, 10);
    EXPECT_EQ(result.minute, 34);
}

TEST(Addition, addition6)
{
    Time time("11:30");

    Time result = time + (-275);

    EXPECT_EQ(result.hour, 6);
    EXPECT_EQ(result.minute, 55);
}

TEST(Addition, addition7)
{
    Time time("23:45");

    Time result = time + 30;

    EXPECT_EQ(result.hour, 0);
    EXPECT_EQ(result.minute, 15);
}

TEST(Addition, addition8)
{
    Time time("23:45");

    Time result = time + 95;

    EXPECT_EQ(result.hour, 1);
    EXPECT_EQ(result.minute, 20);
}

TEST(Addition, addition9)
{
    Time time("00:15");

    Time result = time + (-30);

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 45);
}

TEST(Addition, addition10)
{
    Time time("01:30");

    Time result = time + (-95);

    EXPECT_EQ(result.hour, 23);
    EXPECT_EQ(result.minute, 55);
}

TEST(Addition, addition11)
{
    Time time("01:30");

    Time result = time + (24 * 60);

    EXPECT_EQ(time, result);
}
TEST(Addition, addition12)
{
    Time time("01:30");

    Time result = time + (-24 * 60);

    EXPECT_EQ(time, result);
}

TEST(Addition, addition13)
{
    Time time("01:22");
    Time duration("8:30");

    Time result = time + duration;

    EXPECT_EQ(result.hour, 9);
    EXPECT_EQ(result.minute, 52);
}

TEST(Addition, addition14)
{
    Time time("01:22");
    Time duration("01:58");

    Time result = time + duration;

    EXPECT_EQ(result.hour, 03);
    EXPECT_EQ(result.minute, 20);
}

TEST(Addition, addition15)
{
    Time time("23:47");
    Time duration("02:22");

    Time result = time + duration;

    EXPECT_EQ(result.hour, 2);
    EXPECT_EQ(result.minute, 9);
}
