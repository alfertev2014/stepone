#include <gtest/gtest.h>

#include <sstream>

#include <firstparser.h>
#include <initevaluator.h>
#include <initsymbols.h>

using namespace stepone::parser;
using namespace stepone::init;

TEST(FirstParserTest, Parcing) {
    FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());
    auto nil = fp.parse("()");
    std::stringstream ss;
    fp.print(ss, nil);
    auto str = ss.str();

    EXPECT_EQ(str, "()");
}

