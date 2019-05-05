#pragma once

#include <ptr.h>

namespace stepone::base {

using namespace core;

class MQuote {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MApply {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MIf {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MLet {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MLazy {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MUnlazy {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MLabel {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MLambda {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MMacro {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MCurrentContext {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MTry {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MBot {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

class MGenSymbol {
public:
    static Ptr apply(const Ptr &p, const Ptr &a);
};

} // namespaces
