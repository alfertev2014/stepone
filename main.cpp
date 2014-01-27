
#include "test.h"
#include "repl.h"

int main() {
    TestFastParser tfp;
    tfp.test_all();
    return REPL::do_loop();
}

