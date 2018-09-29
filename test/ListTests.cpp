#include <gtest/gtest.h>
#include "Node.hpp"
#include "List.hpp"
#include <memory>

struct ListTests : public ::testing::Test
{
    //GIVEN
    List<int> list;
    std::shared_ptr<Node<int>> node5 = std::make_shared<Node<int>>(5);
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
    ASSERT_EQ(list.getTail()->value,5);
}
