#pragma once

#include "dbg.h"
#include <string>
#include <fstream>

#include "stepone.h"
#include "fastparser.h"

using namespace std;

class TestEngine {
    FastParser fp;
public:
    TestEngine(const FastParser & _fp) :fp(_fp){}

    void test_from_file(const string &fname) {
        cout << "_______________________________________________________________________________________________" << endl;
        cout << "===============================================================================================" << endl;
        cout << "Open test file " << fname << endl;
        ifstream testfile(fname.c_str());
        if(!testfile.is_open()) {
            cout << "Can\'t open " << fname << endl;
            return;
        }
        string s;
        string res;
        int i = 0;
        while(getline(testfile, s)) {
            i++;
            bool exc = false;
            if(!s.empty() && s[0] != ';') {
                cout << "line " << i << ": >>  " << s << endl;
                try {
                res = fp.evalToString(s);
                } catch (const SemanticError &e) {
                    exc = true;
                    res = ";fail";
                }
                cout << res << endl;
            } else continue;
            if(getline(testfile, s)) {
                if(s != res && !exc) {
                    cout << " * * * * ** ** ** *** *** **** !!! FAIL !!! **** *** *** ** ** ** * * * * " << endl;
                    cout << "must be: " << s << endl << endl;
                }
                i++;
            }
        }
        cout << "All tests in file " << fname << " done" << endl;
        cout << "===============================================================================================" << endl << endl;
    }
};
