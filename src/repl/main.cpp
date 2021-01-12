
#include "repl.h"

#include <firstparser.h>

#include "initsymbols.h"
#include "initevaluator.h"

#include <iostream>

using namespace stepone::init;
using namespace stepone::parser;

int main() {
    try {
        FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());
        return REPL::do_loop(fp);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

