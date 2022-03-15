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
        auto parsed = fp.parse(s);
        std::cout << " echo:    ";
        fp.print(std::cout, parsed);
        std::cout << std::endl;
        std::cout << " result:  ";
        fp.print(std::cout, fp.eval(parsed));
        std::cout << std::endl;
    }
    return 0;
}
