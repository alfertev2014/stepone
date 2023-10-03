#include <gtest/gtest.h>

#include <firstparser.h>
#include <initevaluator.h>
#include <initsymbols.h>

using namespace stepone;
using namespace stepone::parser;
using namespace stepone::init;

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

