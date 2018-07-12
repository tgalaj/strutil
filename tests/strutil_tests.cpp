#include <gtest/gtest.h>
#include "strutil.h"

TEST(Parsing, int_to_string)
{
    EXPECT_EQ("255", strutil::to_string<int>(255));
}

TEST(Parsing, float_to_string)
{
    EXPECT_EQ("5.245", strutil::to_string<float>(5.245f));
}

TEST(Parsing, double_to_string)
{
    EXPECT_EQ("5.245", strutil::to_string<float>(5.245));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}