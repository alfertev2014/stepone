cmake_minimum_required(VERSION 3.14)

project(stepone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
    libstepone
    impl/base/basemacro.cpp

    impl/core/bytearray.cpp
    impl/core/core.cpp
    impl/core/macro.cpp
    impl/core/vector.cpp

    impl/objects/basefunc_obs.cpp
    impl/objects/basemacro_obs.cpp
    impl/objects/basenumfunc_obs.cpp
    impl/objects/bytearray_obs.cpp
    impl/objects/typepredicates_obs.cpp
    impl/objects/vector_obs.cpp

    impl/ob.cpp
    impl/logging.cpp
)

target_include_directories(
    libstepone
    PUBLIC include/stepone impl/include
)

add_library(
    steponeinit
    init/initevaluator.cpp
    init/initsymbols.cpp
)
target_include_directories(
    steponeinit
    INTERFACE init
)
target_link_libraries(steponeinit PUBLIC libstepone)

add_library(steponeparser  parser/firstparser.cpp)
target_include_directories(steponeparser INTERFACE parser)
target_link_libraries(steponeparser PUBLIC steponeinit)


add_executable(
    steponerepl
    repl/main.cpp
    repl/repl.cpp
)

target_link_libraries(steponerepl steponeparser)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  steponetest
  test/parser.cpp
  test/runtime.cpp
  test/info.cpp
)
target_link_libraries(
  steponetest
  gtest_main
)
target_link_libraries(steponetest steponeparser)

include(GoogleTest)
gtest_discover_tests(steponetest)
