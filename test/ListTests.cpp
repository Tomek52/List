#include <gtest/gtest.h>
#include "Node.hpp"
#include "List.hpp"
#include <memory>

struct ListTests : public ::testing::Test
{
    //GIVEN
    List<int> list;
    std::shared_ptr<Node<int>> node5 = std::make_shared<Node<int>>(5);
    std::shared_ptr<Node<int>> node30 = std::make_shared<Node<int>>(30);
    std::shared_ptr<Node<int>> node33 = std::make_shared<Node<int>>(33);
    std::shared_ptr<Node<int>> node3 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> node0 = std::make_shared<Node<int>>(0);
};

TEST_F(ListTests, GivenEmptyListShouldHaveNullptrOnHeadAndTail)
{
    //THEN
    ASSERT_EQ(list.getTail(), nullptr);
    ASSERT_EQ(list.getHead(), nullptr);
}

TEST_F(ListTests, GivenListWhenAddNode5TailShouldHaveValue5)
{
    //WHEN
    list.add(node5);
    //THEN
    ASSERT_EQ(list.getTail()->value, 5);
}

TEST_F(ListTests, GivenListWhenAddNode30TailShouldHaveValue30)
{
    //WHEN
    list.add(node5);
    list.add(node30);
    //THEN
    ASSERT_EQ(list.getTail()->value, 30);
}

TEST_F(ListTests, GivenNodesWhenAddNodesToListFindNodeWithValue3)
{
    //WHEN
    list.add(node5);
    list.add(node30);
    list.add(node33);
    list.add(node3);
    list.add(node0);
    //THEN
    ASSERT_EQ(list.find(3)->value, 3);
}

TEST_F(ListTests, GivenNodesWhenAddNodesToListFindNodeWithValuei4ShouldReturnNullptr)
{
    //WHEN
    list.add(node5);
    list.add(node30);
    list.add(node33);
    list.add(node3);
    list.add(node0);
    //THEN
    ASSERT_EQ(list.find(4), nullptr);
}
