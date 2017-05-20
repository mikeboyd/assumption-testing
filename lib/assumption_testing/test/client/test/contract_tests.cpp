/// @copyright Mike Boyd
/// @date 2017

#include <gtest/gtest.h>
#include "assumption_testing/test/dependency/include/class.h"

TEST(ContractTest, TestVoidVoid)
{
  Class c;
  ASSERT_NO_THROW(c.void_void());
}

TEST(ContractTest, TestVoidInt)
{
  Class c;
  ASSERT_NO_THROW(c.void_int(3));
}
