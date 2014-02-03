#ifndef REPL_H
#define REPL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "fastparser.h"

class REPL {
public:
    static int do_loop() {
        cout << "StepOne REPL" << endl;
        cout << "------------" << endl;
        //cout << "Please, load the initial library" << endl;
        FastParser fp;

        string libfilename = "../stepone/initlib.txt";
        //getline(cin, libfilename);
        ifstream f(libfilename.c_str());

        if(f.is_open()) {
            cout << "initlib has opened" << endl;
            string s;
            string lib;
            while(getline(f, s)) {
                lib += s;
                lib += ' ';
            }
            cout << "initlib:" << endl << lib << endl;
            fp.loadInitLibrary(lib);
            cout << "initlib has loaded" << endl;
        }

        while(true) {
            cout << "~> ";
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
