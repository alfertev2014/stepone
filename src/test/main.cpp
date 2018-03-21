#include "test.h"

#include <parser/firstparser.h>

#include <init/initsymbols.h>
#include <init/initevaluator.h>

using namespace stepone::init;
using namespace stepone::parser;

int main() {
    FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());

    TestEngine tfp(fp);
    tfp.test_from_file("./other/test.txt"); // hardcoded!!!

    return 0;
}

