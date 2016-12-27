#pragma once

#include <ob.h>

class IOFunctions {
    IOFunctions();
public:
    static const IOFunctions &inst();

    const Ptr finputp;
    const Ptr foutputp;
    const Ptr fopenin;
    const Ptr fopenout;
    const Ptr fread;
    const Ptr fwrite;

    const Ptr stdin;
    const Ptr stdout;
    const Ptr stderr;
};
