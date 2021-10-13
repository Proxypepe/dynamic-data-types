#include <gtest/gtest.h>
#include "../List.h"


class ListTest : public ::testing::Test
{
public:
    List<int> l;

protected:
        void SetUp() override
        {
            l.push_back(10);
            l.push_back(20);
            l.push_back(30);
        }
};


TEST_F(ListTest, SIZE)
{
    EXPECT_EQ(l.size(), 3);
}

TEST_F(ListTest, PUSH_BACK)
{
    l.push_back(40);
    EXPECT_EQ(l[3],  40);
    EXPECT_EQ(l.size(), 4);
    l.clear();
    l.push_back(50);
    EXPECT_EQ(l[0], 50);
    EXPECT_EQ(l.size(), 1);
}

TEST_F(ListTest, POP_BACK)
{
    l.pop_back();
    EXPECT_EQ(l[1],  20);
    EXPECT_EQ(l.size(), 2);
    l.clear();
    l.pop_back();
    EXPECT_EQ(l.size(), 0);
}

TEST_F(ListTest, PUSH_FRONT)
{
    l.push_front(40);
    EXPECT_EQ(l[0],  40);
    EXPECT_EQ(l.size(), 4);
    l.clear();
    l.push_back(50);
    EXPECT_EQ(l[0], 50);
    EXPECT_EQ(l.size(), 1);
}

TEST_F(ListTest, POP_FRONT)
{
    l.pop_front();
    EXPECT_EQ(l[0],  20);
    EXPECT_EQ(l.size(), 2);
    l.clear();
    l.pop_front();
    EXPECT_EQ(l.size(), 0);
}

TEST_F(ListTest, INSERT)
{
    l.insert(1, 50);
    EXPECT_EQ(l[1],  50);
    EXPECT_EQ(l.size(), 4);

    l.insert(0, 60);
    EXPECT_EQ(l[0],  60);
    EXPECT_EQ(l.size(), 5);
    auto _size = l.size();
    l.insert(_size, 70);
    EXPECT_EQ(l[_size],  70);
    EXPECT_EQ(l.size(), _size + 1);   

}

TEST_F(ListTest, REMOVE)
{
    auto _size = l.remove(10);
    EXPECT_EQ(_size,  1);
    EXPECT_EQ(l.size(), 2);

    l.emplace_back(40, 50, 40);
    _size = l.remove(40);
    EXPECT_EQ(_size, 2);
    EXPECT_EQ(l.size(), 3);
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}