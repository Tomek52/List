#include <gtest/gtest.h>
#include "Node.hpp"
#include "List.hpp"

struct ListTests : public ::testing::Test
{
    List<int> list;
};

TEST_F(ListTests, GivenEmptyListShouldHaveNullptrOnHeadAndTail)
{
    //THEN
    ASSERT_EQ(list.getTail(), nullptr);
    ASSERT_EQ(list.getHead(), nullptr);
}
