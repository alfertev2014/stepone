#pragma once

#include <string>

#include <parser/firstparser.h>

class TestEngine {
    stepone::parser::FirstParser fp;
public:
    TestEngine(const stepone::parser::FirstParser & _fp) :fp(_fp){}

    void test_from_file(const std::string &fname);
};
