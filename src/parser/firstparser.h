#pragma once

#include <ptr.h>
#include <string>
#include <memory>

namespace stepone::parser {

class FirstParser {
public:
    FirstParser(const Ptr &baseEvaluator, const Ptr &baseSymbolTable);
    FirstParser(const FirstParser &fp);
    ~FirstParser();

    Ptr parse(const std::string & _s);
    Ptr parseEval(const std::string & s);
    Ptr eval(const Ptr &p);
    std::string evalToString(const std::string & _s);

    void print(std::ostream & ts, const Ptr & p);
    std::string printToString(const Ptr & p);

private:
    class FirstParserImpl;
    Ptr a;
    std::unique_ptr<FirstParserImpl> impl;
};

} // namespaces
