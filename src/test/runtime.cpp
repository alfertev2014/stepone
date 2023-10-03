#include <gtest/gtest.h>

#include <core/core.h>

using namespace stepone;
using namespace stepone::core;

TEST(Obs,CheckObType) {
    Ptr nil = Ptr::anil();
    EXPECT_TRUE(nil.is<Symbol>());
    EXPECT_TRUE(nil.is<Atom>());
    EXPECT_FALSE(nil.is<Pair>());
    EXPECT_FALSE(nil.is<Const>());
}
