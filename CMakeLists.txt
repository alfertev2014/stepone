cmake_minimum_required(VERSION 3.0)

project(stepone)

add_library(libstepone
    src/impl/base/basemacro.cpp

    src/impl/core/bytearray.cpp
    src/impl/core/core.cpp
    src/impl/core/io.cpp
    src/impl/core/macro.cpp
    src/impl/core/ob.cpp
    src/impl/core/value.cpp
    src/impl/core/vector.cpp

    src/impl/objects/basefunc_obs.cpp
    src/impl/objects/basemacro_obs.cpp
    src/impl/objects/basenumfunc_obs.cpp
    src/impl/objects/bytearray_obs.cpp
    src/impl/objects/io_obs.cpp
    src/impl/objects/typepredicates_obs.cpp
    src/impl/objects/vector_obs.cpp

    src/impl/symbols/basesymbols.cpp)

target_include_directories(libstepone
    PUBLIC src/include/stepone
    )


add_library(steponeparser
    src/init/initevaluator.cpp
    src/init/initsymbols.cpp

    src/parser/firstparser.cpp
    )

add_executable(steponerepl
    src/repl/main.cpp
    src/repl/repl.cpp
    )

add_executable(steponetest
    src/test/main.cpp
    src/test/test.cpp
    )

target_link_libraries(steponeparser libstepone)

target_link_libraries(steponerepl steponeparser libstepone)

target_link_libraries(steponetest steponeparser libstepone)

