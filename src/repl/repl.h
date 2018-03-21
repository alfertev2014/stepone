#pragma once

namespace stepone { namespace parser {
    class FirstParser;
}}

class REPL {
public:
    static int do_loop(stepone::parser::FirstParser &fp);
};
