#include "test.h"

#include <parser/firstparser.h>

#include <init/initsymbols.h>
#include <init/initevaluator.h>

#include <iostream>

using namespace stepone::init;
using namespace stepone::parser;

int main(int argc, char *argv[]) {
    try {
        FirstParser fp(BaseEvaluator::createContext(), BaseSymbolTable::createSymbolTable());

	std::string filename;
        if (argc >= 2) {
            filename.append(argv[1]);
        }
	else {
            filename.append("./other/test.txt");
        }

        TestEngine tfp(fp);
        tfp.test_from_file(filename);

        return 0;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

