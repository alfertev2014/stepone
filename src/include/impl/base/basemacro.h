#pragma once

#include <impl/core/macro.h>

class MQuote : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MApply : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MIf : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MLet : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MLazy : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MUnlazy : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MLabel : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MLambda : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MMacro : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MCurrentContext : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MTry : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MBot : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

class MGenSymbol : public BaseMacro {
public:
    Ptr apply(const Ptr &p, const Ptr &a);
};

