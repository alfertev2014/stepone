#include <gtest/gtest.h>

#include <sstream>

#include <firstparser.h>
#include <initevaluator.h>
#include <initsymbols.h>

#include <core/core.h>

using namespace stepone;
using namespace stepone::core;
using namespace stepone::parser;
using namespace stepone::init;

TEST(Obs,CheckObType) {
    Ptr nil = Ptr::anil();
    EXPECT_TRUE(nil.is<Symbol>());
    EXPECT_TRUE(nil.is<Atom>()); // TODO: failed test
    EXPECT_FALSE(nil.is<Pair>());
    EXPECT_FALSE(nil.is<Const>());
}

TEST(Parcing, ParcingOnlyParentheses) {
    FirstParser fp(Ptr::anil(), Ptr::anil());

    static const char *table[][2] = {
        {"()", "()"},
        {"(())", "(())"}
    };

    for (auto str : table) {
        std::cout << str[0] << std::endl;
        auto res = fp.printToString(fp.parse(str[0]));
        EXPECT_EQ(res, str[1]);
    }
}

