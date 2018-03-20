
#include "repl.h"

#include <parser/firstparser.h>

#include <init/initsymbols.h>
#include <init/initevaluator.h>

int main() {
    FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());
    return REPL::do_loop(fp);
}

