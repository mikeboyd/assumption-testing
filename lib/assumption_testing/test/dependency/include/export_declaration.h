/// @brief Export declaration.
/// @copyright Mike Boyd
/// @date 2017


#ifndef LIB_ASSUMPTION_TESTING_TEST_DEPENDENCY_INCLUDE_EXPORT_DECLARATION_H_
#define LIB_ASSUMPTION_TESTING_TEST_DEPENDENCY_INCLUDE_EXPORT_DECLARATION_H_


#if defined(_WIN32) && defined(DEPENDENCY_LIB_SHARED) && defined(DEPENDENCY_EXPORT)
# define DEPENDENCY_API __declspec(dllexport)
#elif defined(_WIN32) && defined(TEST_EXE)
# define DEPENDENCY_API __declspec(dllimport)
#else
# define DEPENDENCY_API
#endif


#endif  // LIB_ASSUMPTION_TESTING_TEST_DEPENDENCY_INCLUDE_EXPORT_DECLARATION_H_
