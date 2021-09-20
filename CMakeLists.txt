cmake_minimum_required(VERSION 3.11.0)
project(CPP_HTTP VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  message("-- Compiling with MSVC")
  add_compile_options(-W4)
  string(REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  message("-- Compiling with Clang")
  add_compile_options(-Wall -Wextra -Werror -Wdouble-promotion -fno-common -Wno-sign-compare)
else()
  message("-- Compiling with GCC")
  add_compile_options(-Wall -Wextra -Werror -Wdouble-promotion -Wconversion -fno-common -Wno-sign-compare)
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(FetchContent)

include_directories(include)

file(GLOB include_files
     "include/*.cpp"
     "include/*.hpp"
)

add_executable(Get src/Get.cpp ${include_files} )
add_executable(Post src/Post.cpp ${include_files} )

if (WIN32)
  target_link_libraries(Get Ws2_32.lib)
  target_link_libraries(Post Ws2_32.lib)
endif (WIN32)

target_clangformat_setup(Get)
target_clangformat_setup(Post)