#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(Assign, assign1)
{
    Time time1("18:45");
    Time time2 = time1;

    EXPECT_EQ(time2.hour, 18);
    EXPECT_EQ(time2.minute, 45);
}

TEST(Assign, assign2)
{
    Time time1("17:33");
    Time time2;

    EXPECT_EQ(time2.hour, 0);
    EXPECT_EQ(time2.minute, 0);

    time2 = time1;

    EXPECT_EQ(time2.hour, 17);
    EXPECT_EQ(time2.minute, 33);
}