cmake_minimum_required(VERSION 2.8)

##
# CMake build script for Assumption Testing
##

option(BUILD_SHARED_LIBS "build shared library" OFF)

project(assumption-testing CXX)

if(${MSVC})
  if (${BUILD_SHARED_LIBS})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  endif (${BUILD_SHARED_LIBS})
endif(${MSVC})

add_subdirectory(thirdparty/googletest)

if (${BUILD_SHARED_LIBS})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_LINKED_AS_SHARED_LIBRARY=1")
endif (${BUILD_SHARED_LIBS})

if(${MSVC})
  if (${BUILD_SHARED_LIBS})
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
  else (${BUILD_SHARED_LIBS})
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  endif (${BUILD_SHARED_LIBS})
endif(${MSVC})


include(CheckCXXCompilerFlag)

if (${CMAKE_COMPILER_IS_GNUCXX})
  CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
  if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  else(COMPILER_SUPPORTS_CXX11)
    message(FATAL_ERROR "your compiler does not support C++11")
  endif(COMPILER_SUPPORTS_CXX11)
endif (${CMAKE_COMPILER_IS_GNUCXX})


include_directories(lib include)

option(AT_BUILD_TESTS "build assumption-testing unit tests" ON)
if (${AT_BUILD_TESTS})
  enable_testing()
  add_subdirectory(lib/assumption_testing/test)
endif (${AT_BUILD_TESTS})

install(
  DIRECTORY   ${PROJECT_SOURCE_DIR}/include/assumption-testing
  DESTINATION include
)

add_library(assumption-testing)
target_link_libraries(assumption-testing gmock gtest)
set_target_properties(assumption-testing PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(assumption-testing INTERFACE include)
