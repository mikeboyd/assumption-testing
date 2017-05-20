/// @copyright Mike Boyd
/// @date 2017

#include <gmock/gmock.h>
#include "assumption_testing/test/dependency/include/class.h"

class MockClass
  : public Class
{
public:
  MOCK_METHOD0(void_void, void());
  MOCK_METHOD1(void_int, void(int));
};

TEST(ExpectationTest, TestVoidVoid)
{
  MockClass mc;
  EXPECT_CALL(mc, void_void());
  mc.void_void();
}

TEST(ExpectationTest, TestVoidInt)
{
  MockClass mc;
  EXPECT_CALL(mc, void_int(3));
  mc.void_int(3);
}
