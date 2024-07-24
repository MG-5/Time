#include "../Time.hpp"
#include <gtest/gtest.h>

TEST(OutputOperator, output1)
{
    Time time("11:30");
    std::stringstream out;
    out << time;
    EXPECT_EQ(out.str(), "11:30:00");
}

TEST(OutputOperator, output2)
{
    Time time("1:3");
    std::stringstream out;
    out << time;
    EXPECT_EQ(out.str(), "01:03:00");
}

TEST(OutputOperator, output3)
{
    Time time("26:75");
    std::stringstream out;
    out << time;
    EXPECT_EQ(out.str(), "03:15:00");
}