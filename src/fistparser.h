#pragma once

#include "dbg.h"

#include "core.h"

using namespace std;

class FirstParser {
public:
    FirstParser();
    FirstParser(const FirstParser &fp);
    ~FirstParser();

    Ob::Ptr parse(const string & _s);
    Ob::Ptr parseEval(const string & s);
    string evalToString(const string & _s);

    void print(ostream & ts, const Ob::Ptr & p);

private:
    class FirstParserImpl;
    Ob::Ptr a;
    FirstParserImpl *impl;
};
