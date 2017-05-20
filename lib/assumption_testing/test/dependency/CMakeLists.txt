project(dependency CXX)

set(SOURCES
  src/class.cpp
)

set(HEADERS
  include/class.h
  include/export_declaration.h
)

include_directories(
  include
)

if(${BUILD_SHARED_LIBS})
  if (${MSVC})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DDEPENDENCY_EXPORT")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DDEPENDENCY_LIB_SHARED")
  else (${MSVC})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEPENDENCY_LIB_SHARED")
  endif (${MSVC})
endif(${BUILD_SHARED_LIBS})

add_library(${PROJECT_NAME}
  ${SOURCES}
  ${HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
