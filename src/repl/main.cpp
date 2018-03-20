
#include "repl.h"

#include <parser/fistparser.h>

#include <init/initsymbols.h>
#include <init/initevaluator.h>

int main() {
    FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());
    return REPL::do_loop(fp);
}

