#include "test.h"

#include <parser/firstparser.h>

#include <init/initsymbols.h>
#include <init/initevaluator.h>

#include <iostream>

using namespace stepone::init;
using namespace stepone::parser;

int main() {
    try {
        FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());

        TestEngine tfp(fp);
        tfp.test_from_file("./other/test.txt"); // hardcoded!!!

        return 0;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

