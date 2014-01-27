#ifndef TEST_H
#define TEST_H

#include "dbg.h"
#include <string>

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
    void test_base_macro() {
        test_eq("()", "()", SDBG(""));
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
        test_base_macro();
        test_base_func();
        cout << "all right!" << endl;
    }
};

#endif // TEST_H
