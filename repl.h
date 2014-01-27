#ifndef REPL_H
#define REPL_H

#include <iostream>
#include <string>

using namespace std;

#include "fastparser.h"

class REPL {
public:
    static int do_loop() {
        cout << "StepOne REPL" << endl;
        cout << "------------" << endl;
        FastParser fp;
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
