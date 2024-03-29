#pragma once

#include <ptr.h>

namespace stepone::builtin {

class MQuote {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MApply {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MIf {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MLet {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MMacro {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MTry {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MBot {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

class MGenSymbol {
public:
    Ptr operator()(const Ptr &p, const Ptr &a) const;
};

} // namespaces
