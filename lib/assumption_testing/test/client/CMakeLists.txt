project(client CXX)

set(SOURCES
  test/google_test_main.cpp
  test/contract_tests.cpp
  test/collaboration_tests.cpp
)

set(HEADERS
)

include_directories(
)

if(${BUILD_SHARED_LIBS})
  if (${MSVC})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DTEST_EXE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DCLIENT_LIB_SHARED")
  else (${MSVC})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCLIENT_LIB_SHARED")
  endif (${MSVC})
endif(${BUILD_SHARED_LIBS})

add_executable(
  ${PROJECT_NAME}
  ${SOURCES}
  ${HEADERS}
)

target_link_libraries(
  ${PROJECT_NAME}
  dependency
  gtest
  gmock
)

add_test(
  NAME test-client
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  COMMAND client
)
