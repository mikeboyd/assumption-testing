/// @copyright Mike Boyd
/// @date 2017

#ifndef LIB_ASSUMPTION_TESTING_TEST_DEPENDENCY_INCLUDE_CLASS_H_
#define LIB_ASSUMPTION_TESTING_TEST_DEPENDENCY_INCLUDE_CLASS_H_

#include "assumption_testing/test/dependency/include/export_declaration.h"

class DEPENDENCY_API Class
{
public:
  Class() = default;
  Class(const Class&) = default;
  Class& operator=(const Class&) = default;

  void void_void() const;
  void void_int(int) const;
};

#endif // LIB_ASSUMPTION_TESTING_TEST_DEPENDENCY_INCLUDE_CLASS_H_
