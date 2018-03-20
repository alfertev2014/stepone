#pragma once

#include <string>

#include <parser/fistparser.h>

class TestEngine {
    FirstParser fp;
public:
    TestEngine(const FirstParser & _fp) :fp(_fp){}

    void test_from_file(const std::string &fname);
};
