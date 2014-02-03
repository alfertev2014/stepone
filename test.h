#ifndef TEST_H
#define TEST_H

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
            throw 0;
        }
    }
public:
    TestFastParser(const FastParser & _fp) :fp(_fp){}

    void test_base_macro() {
        test_eq("()", "()", SDBG());
        test_eq("(\' . a)", "a", SDBG());
        test_eq("(\' a)", "(a)", SDBG());
        test_eq("(\' a b c)", "(a b c)", SDBG());
        test_eq("(? (\' . t) (\' . a) \' . b)", "a", SDBG());
        test_eq("(? () (\' . a) \' . b)", "b", SDBG());
        test_eq("((\\ x x) (\' . y))", "y", SDBG());
        test_eq("(>- x (\' . y) . x)", "y", SDBG());
    }

    void test_base_func() {
        test_eq("(car (\' a))", "a", SDBG());
        test_eq("(cdr (\' a))", "()", SDBG());
        test_eq("(cons (\' . a) (\' . b))", "(a . b)", SDBG());
        test_eq("(cons (\' a) (\' b))", "((a) b)", SDBG());
    }

    void test_all() {
        test_from_file();
        cout << "all tests is done!" << endl << endl;
    }

    void test_from_file() {
        string fname("../stepone/test.txt");
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
                } catch (int e) {
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

#endif // TEST_H
