#include "repl.h"

#include <firstparser.h>

#include <iostream>
#include <string>

int REPL::do_loop(stepone::parser::FirstParser &fp) {
    std::cout << "StepOne REPL" << std::endl;
    std::cout << "------------" << std::endl;

    while(true) {
        std::cout << "alz> ";
        std::string s;
        std::getline(std::cin, s);
        if (s == ":quit" || std::cin.eof())
            break;
	else if (s.empty())
            continue;
        fp.print(std::cout, fp.parseEval(s));
        std::cout << std::endl;
    }
    return 0;
}
