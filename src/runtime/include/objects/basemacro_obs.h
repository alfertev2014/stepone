#pragma once

#include <ptr.h>

namespace stepone::objects {

class BaseMacroses {
    BaseMacroses();
public:
    static const BaseMacroses &inst();

    const Ptr aquote;
    const Ptr aapply;
    const Ptr aif;
    const Ptr alet;
    const Ptr amacro;
    const Ptr acurctx;
    const Ptr atry;
    const Ptr abot;
    const Ptr agensym;

    Ptr populateContext(const Ptr &a) const;
};

} // namespaces
