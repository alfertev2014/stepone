#ifndef REPL_H
#define REPL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "fastparser.h"
#include "test.h"

class REPL {
public:
    static int do_loop() {
        cout << "StepOne REPL" << endl;
        cout << "------------" << endl;
        //cout << "Please, load the initial library" << endl;
        FastParser fp;

        string libfilename = "../stepone/initlib.txt";
        //getline(cin, libfilename);
        ifstream initlibfile(libfilename.c_str());

        if(initlibfile.is_open()) {
            cout << "initlib has opened" << endl;
            string s;
            string lib;
            while(getline(initlibfile, s)) {
                lib += s;
                lib += ' ';
            }
            //cout << "initlib:" << endl << lib << endl;
            fp.loadInitLibrary(lib);
            cout << "initlib has loaded" << endl;
        }

        TestFastParser tfp(fp);
        tfp.test_all();

        while(true) {
            cout << "alz> ";
            string s;
            getline(cin, s);
            if(s == ":exit") break;
            fp.print(cout, fp.parseEval(s));
            cout << endl;
        }
        return 0;
    }
};

#endif // REPL_H
