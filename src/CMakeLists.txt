cmake_minimum_required(VERSION 3.0)

project(stepone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(libstepone
    impl/base/basemacro.cpp

    impl/core/bytearray.cpp
    impl/core/core.cpp
    impl/core/macro.cpp
    impl/core/ob.cpp
    impl/core/vector.cpp

    impl/objects/basefunc_obs.cpp
    impl/objects/basemacro_obs.cpp
    impl/objects/basenumfunc_obs.cpp
    impl/objects/bytearray_obs.cpp
    impl/objects/typepredicates_obs.cpp
    impl/objects/vector_obs.cpp)

target_include_directories(libstepone
    PUBLIC include/stepone
    )


add_library(steponeparser
    init/initevaluator.cpp
    init/initsymbols.cpp

    parser/firstparser.cpp
    )

target_include_directories(steponeparser
    PUBLIC include/stepone
    )

add_executable(steponerepl
    repl/main.cpp
    repl/repl.cpp
    )

target_include_directories(steponerepl
    PUBLIC include/stepone
    )

add_executable(steponetest
    test/main.cpp
    test/test.cpp
    )

target_include_directories(steponetest
    PUBLIC include/stepone
    )

target_link_libraries(steponeparser libstepone)

target_link_libraries(steponerepl steponeparser libstepone)

target_link_libraries(steponetest steponeparser libstepone)

