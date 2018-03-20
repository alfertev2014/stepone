#include "repl.h"

#include <iostream>
#include <string>
#include <fstream>

#include <parser/fistparser.h>

int REPL::do_loop(FirstParser &fp) {
    std::cout << "StepOne REPL" << std::endl;
    std::cout << "------------" << std::endl;

    while(true) {
        cout << "alz> ";
        std::string s;
        std::getline(std::cin, s);
        if (s == ":quit")
            break;
        fp.print(cout, fp.parseEval(s));
        std::cout << std::endl;
    }
    return 0;
}
