#include "../src/linked_list.h"
#include <gtest/gtest.h>
#include <cstddef>

TEST(Constructor, default_)
{
    LinkedList<int> l;
    ASSERT_EQ(l.GetLength(), 0);
    ASSERT_THROW(l.GetFirst(), std::out_of_range);
    ASSERT_THROW(l.GetLast(), std::out_of_range);
}
TEST(Methods, Append)
{
    LinkedList<int> l;
    ASSERT_NO_THROW(l.Append(1));
    EXPECT_EQ(l.GetFirst(), 1);
    EXPECT_EQ(l.GetLast(), 1);
    ASSERT_NO_THROW(l.Append(2));
    EXPECT_EQ(l.GetFirst(), 1);
    EXPECT_EQ(l.GetLast(), 2);
    EXPECT_EQ(l.GetLength(), 2);
}

TEST(Methods, Prepend)
{
    LinkedList<int> l;
    ASSERT_NO_THROW(l.Prepend(1));
    EXPECT_EQ(l.GetFirst(), 1);
    EXPECT_EQ(l.GetLast(), 1);
    ASSERT_NO_THROW(l.Prepend(2));
    EXPECT_EQ(l.GetFirst(), 2);
    EXPECT_EQ(l.GetLast(), 1);
    EXPECT_EQ(l.GetLength(), 2);
}

TEST(Methods, Get)
{
    LinkedList<int> l;
    ASSERT_NO_THROW(l.Append(1));
    ASSERT_NO_THROW(l.Append(2));
    ASSERT_NO_THROW(l.Prepend(3));
    ASSERT_NO_THROW(l.Get(1));
    EXPECT_EQ(l.Get(1), 1);
    ASSERT_THROW(l.Get(5), std::out_of_range);
    ASSERT_THROW(l.Get(3), std::out_of_range);
    ASSERT_THROW(l.Get(-2), std::out_of_range);

    int items[8] = {9, 2, 3, 1, 2, 1, 6, 4}; 
    l.Append(1);
    l.Append(6);
    l.Prepend(2);
    l.Append(4);
    l.Prepend(9);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(l.Get(i), items[i]);
    }
    EXPECT_EQ(l.GetLength(), 8);
}

TEST(Constructor, copying_from_array)
{
    int items[10] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 10};
    LinkedList<int> l(items, 10);
    ASSERT_EQ(l.GetLength(), 10);
    EXPECT_EQ(l.GetFirst(), 1);
    EXPECT_EQ(l.GetLast(), 10);

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(l.Get(i), items[i]);
    }
}

TEST(Methods, InsertAt)
{
    int items[10] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 10};
    LinkedList<int> l(items, 10);
    ASSERT_NO_THROW(l.InsertAt(11, 4));
    ASSERT_EQ(l.GetLength(), 10);
    ASSERT_THROW(l.InsertAt(0, -1), std::out_of_range);
    ASSERT_THROW(l.InsertAt(0, 11), std::out_of_range);
    ASSERT_THROW(l.InsertAt(0, 14), std::out_of_range);
    ASSERT_NO_THROW(l.InsertAt(12, 0));
    ASSERT_NO_THROW(l.InsertAt(13, 9));

    int new_items[10] = {12, 2, 3, 4, 11, 6, 7, 8, 9, 13};
    EXPECT_EQ(l.GetFirst(), 12);
    EXPECT_EQ(l.GetLast(), 13);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(l.Get(i), new_items[i]);
    }
}
TEST(Methods, GetSubList)
{
    int items[10] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 10};
    int items2[4] = {3, 4, 5, 6};
    LinkedList<int> l(items, 10);
    LinkedList<int>* l2 = l.GetSubList(2, 5);
    ASSERT_EQ(l2->GetLength(), 4);
    ASSERT_THROW(l.GetSubList(-1, 3), std::out_of_range);
    ASSERT_THROW(l.GetSubList(0, 10), std::out_of_range);
    ASSERT_THROW(l.GetSubList(5, 3), std::out_of_range);
    ASSERT_THROW(l.GetSubList(4, -1), std::out_of_range);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(l2->Get(i), items2[i]);
    }
}
TEST(Methods, Concat)
{
    float items[5] = {1.2, 2.9, 3.1, 4.6, 5.3};
    float items2[4] = {6.4, 7.9, 8.6, 9.3};
    LinkedList<float> l(items, 5);
    LinkedList<float> l2(items2, 4);
    float check_items[9] = {1.2, 2.9, 3.1, 4.6, 5.3, 6.4, 7.9, 8.6, 9.3};
    LinkedList<float>* l3 = l.Concat(&l2);
    ASSERT_EQ(l3->GetLength(), 9);
    ASSERT_FLOAT_EQ(l3->GetFirst(), 1.2);
    ASSERT_FLOAT_EQ(l3->GetLast(), 9.3);
    for (int i = 0; i < 9; i++) {
        EXPECT_FLOAT_EQ(check_items[i], l3->Get(i));
    }
}


