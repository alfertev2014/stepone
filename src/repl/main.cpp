
#include "repl.h"

#include <string>
#include <fstream>

#include <fistparser.h>
#include "../test/test.h"

int main() {
    FirstParser fp;

    //cout << "Please, load the initial library" << endl;

    /*
        string libfilename = "./other/initlib.txt"; // hardcoded!!!
        //std::getline(cin, libfilename);
        std::ifstream initlibfile(libfilename.c_str());

        if(initlibfile.is_open()) {
            std::cout << "initlib was opened" << std::endl;
            std::string s;
            std::string lib;
            while(std::getline(initlibfile, s)) {
                lib += s;
                lib += ' ';
            }
            //std::cout << "initlib:" << std::endl << lib << std::endl;
            fp.loadInitLibrary(lib);
            std::cout << "initlib was loaded" << std::endl;
        }*/


    TestEngine tfp(fp);
    tfp.test_from_file("./other/test.txt"); // hardcoded!!!

    return REPL::do_loop(fp);
}

