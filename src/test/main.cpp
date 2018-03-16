
#include <fistparser.h>
#include "test.h"

int main() {
    FirstParser fp;

    TestEngine tfp(fp);
    tfp.test_from_file("./other/test.txt"); // hardcoded!!!

    return 0;
}

