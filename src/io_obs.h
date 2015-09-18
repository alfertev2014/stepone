#pragma once

#include "core.h"

class IOFunctions {
    IOFunctions();
public:
    static const IOFunctions &inst();

    const Ob::Ptr finputp;
    const Ob::Ptr foutputp;
    const Ob::Ptr fopenin;
    const Ob::Ptr fopenout;
    const Ob::Ptr fread;
    const Ob::Ptr fwrite;

    const Ob::Ptr stdin;
    const Ob::Ptr stdout;
    const Ob::Ptr stderr;
};
