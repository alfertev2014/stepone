#pragma once

#include "dbg.h"
#include <string>
#include <fstream>

#include "stepone.h"
#include "fastparser.h"

using namespace std;

class TestFastParser {
    FastParser fp;


    void test_eq(string e, string res, string mes) {
        if(fp.evalToString(e) != res) {
            cout << mes << endl;
            throw SemanticError();
        }
    }
public:
    TestFastParser(const FastParser & _fp) :fp(_fp){}

    void test_all() {
        test_from_file();
        cout << "all tests has done!" << endl << endl;
    }

    void test_from_file() {
        string fname("../other/test.txt"); // hardcoded!!!
        ifstream testfile(fname.c_str());
        if(!testfile.is_open())
            cout << "Couldn\'t open " << fname << endl;
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
    }
};
