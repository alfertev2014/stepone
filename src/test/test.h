#pragma once

#include <string>

#include "../parser/fistparser.h"

using namespace std;

class TestEngine {
    FirstParser fp;
public:
    TestEngine(const FirstParser & _fp) :fp(_fp){}

    void test_from_file(const string &fname);
};
