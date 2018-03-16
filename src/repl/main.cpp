
#include "repl.h"

#include <fistparser.h>

int main() {
    FirstParser fp;
    return REPL::do_loop(fp);
}

