#include "test.h"

#include <fstream>
#include <iostream>
#include <error_exception.h>

void TestEngine::test_from_file(const std::string &fname) {
    std::cout << "_______________________________________________________________________________________________" << std::endl;
    std::cout << "===============================================================================================" << std::endl;
    std::cout << "Open test file " << fname << std::endl;
    std::ifstream testfile(fname.c_str());
    if(!testfile.is_open()) {
        std::cout << "Can\'t open " << fname << std::endl;
        return;
    }
    std::string s;
    std::string res;
    int i = 0;
    while(getline(testfile, s)) {
        i++;
        bool exc = false;
        if(!s.empty() && s[0] != ';') {
            std::cout << "line " << i << ": >>  " << s << std::endl;
            try {
                res = fp.evalToString(s);
            } catch (const stepone::SemanticError &e) {
                exc = true;
                res = ";fail";
            }
            std::cout << res << std::endl;
        } else continue;
        if(std::getline(testfile, s)) {
            if(s != res && !exc) {
                std::cout << " * * * * ** ** ** *** *** **** !!! FAIL !!! **** *** *** ** ** ** * * * * " << std::endl;
                std::cout << "must be: " << s << std::endl << std::endl;
            }
            i++;
        }
    }
    std::cout << "All tests in file " << fname << " done" << std::endl;
    std::cout << "===============================================================================================" << std::endl << std::endl;
}
