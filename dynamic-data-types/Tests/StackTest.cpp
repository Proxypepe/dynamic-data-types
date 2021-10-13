#include <gtest/gtest.h>
#include "../Stack.h"


class StackTest : public ::testing::Test
{
public:
    Stack<int> s{10000};

protected:
        void SetUp() override
        {
            s.push(10);
            s.push(20);
            s.push(30);
        }
};


TEST_F(StackTest, EMPTY)
{
    EXPECT_EQ(s.empty(), false);
    s.clear();
    EXPECT_EQ(s.empty(), true);
}

TEST_F(StackTest, SIZE)
{
    EXPECT_EQ(s.size(), 3);
}

TEST_F(StackTest, PUSH)
{
    s.push(40);
    EXPECT_EQ(s.top()->data, 40);
    EXPECT_EQ(s.size(), 4);

    s.clear();
    s.push(50);
    EXPECT_EQ(s.top()->data, 50);
    EXPECT_EQ(s.size(), 1);
}

TEST_F(StackTest, POP)
{
    s.pop();
    EXPECT_EQ(s.top()->data, 20);
    EXPECT_EQ(s.size(), 2);
}

TEST_F(StackTest, CLEAR)
{
    s.clear();
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StackTest, TOP)
{
    EXPECT_EQ(s.top()->data, 30);
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}