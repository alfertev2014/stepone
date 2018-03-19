#include "test.h"

#include <fistparser.h>

#include <init/initsymbols.h>
#include <init/initevaluator.h>

int main() {
    FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());

    TestEngine tfp(fp);
    tfp.test_from_file("./other/test.txt"); // hardcoded!!!

    return 0;
}

