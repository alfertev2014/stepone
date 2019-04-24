cmake_minimum_required(VERSION 3.0)

project(stepone)

add_library(libstepone
    impl/base/basemacro.cpp

    impl/core/bytearray.cpp
    impl/core/core.cpp
    impl/core/io.cpp
    impl/core/macro.cpp
    impl/core/ob.cpp
    impl/core/value.cpp
    impl/core/vector.cpp

    impl/objects/basefunc_obs.cpp
    impl/objects/basemacro_obs.cpp
    impl/objects/basenumfunc_obs.cpp
    impl/objects/bytearray_obs.cpp
    impl/objects/io_obs.cpp
    impl/objects/typepredicates_obs.cpp
    impl/objects/vector_obs.cpp

    impl/symbols/basesymbols.cpp)

target_include_directories(libstepone
    PUBLIC include/stepone
    )


add_library(steponeparser
    init/initevaluator.cpp
    init/initsymbols.cpp

    parser/firstparser.cpp
    )

add_executable(steponerepl
    repl/main.cpp
    repl/repl.cpp
    )

add_executable(steponetest
    test/main.cpp
    test/test.cpp
    )

target_link_libraries(steponeparser libstepone)

target_link_libraries(steponerepl steponeparser libstepone)

target_link_libraries(steponetest steponeparser libstepone)

