#pragma once

#include <ptr.h>
#include <string>

using namespace std;

class FirstParser {
public:
    FirstParser();
    FirstParser(const FirstParser &fp);
    ~FirstParser();

    Ptr parse(const string & _s);
    Ptr parseEval(const string & s);
    string evalToString(const string & _s);

    void print(ostream & ts, const Ptr & p);

private:
    class FirstParserImpl;
    Ptr a;
    FirstParserImpl *impl;
};
