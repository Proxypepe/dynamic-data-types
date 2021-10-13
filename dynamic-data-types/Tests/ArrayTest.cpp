#include <gtest/gtest.h>
#include "../Array.h"


class ArrayTest : public ::testing::Test
{
public:
    Array<int> a;

protected:
        void SetUp() override
        {
            a.push_back(10);
            a.push_back(20);
            a.push_back(30);
        }
};


TEST_F(ArrayTest, PUSH_BACK)
{
    a.push_back(40);
    EXPECT_EQ(a[3], 40);
    EXPECT_EQ(a.size(), 4);
    a.clear();
    a.push_back(50);
    EXPECT_EQ(a[0], 50);
    EXPECT_EQ(a.size(), 1);
}

TEST_F(ArrayTest, RESIZE)
{
    a.resize(10);
    EXPECT_EQ(a.size(), 10);
}

TEST_F(ArrayTest, SIZE)
{
    EXPECT_EQ(a.size(), 3);
}

TEST_F(ArrayTest, AT)
{
    EXPECT_EQ(a.at(1), 20);
}

TEST_F(ArrayTest, FRONT)
{
    EXPECT_EQ(a.front(), 10);
}

TEST_F(ArrayTest, BACK)
{
    EXPECT_EQ(a.back(), 30);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}