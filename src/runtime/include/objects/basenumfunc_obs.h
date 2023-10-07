#pragma once

#include <ptr.h>

namespace stepone::objects {

template <typename T>
class BaseNumOps {
public:
    BaseNumOps();

    const Ptr aNeg;
    const Ptr aPlus;
    const Ptr aMinus;
    const Ptr aProduct;
    const Ptr aDivision;
    const Ptr aMod;
    const Ptr aIs;

    const Ptr aAnd;
    const Ptr aOr;
    const Ptr aXor;
    const Ptr aNot;

    const Ptr aShl;
    const Ptr aShr;

    const Ptr aEql;
    const Ptr aNE;
    const Ptr aGT;
    const Ptr aLT;
    const Ptr aGE;
    const Ptr aLE;
    
    const Ptr aSz;
    
    Ptr populateContext(const Ptr &a) const;
};

class BaseNumFunc {
    BaseNumFunc();
public:
    static const BaseNumFunc &inst();

    BaseNumOps<long> longOps;
    BaseNumOps<double> floatOps;
    BaseNumOps<char> charOps;

    const Ptr along2int;
    const Ptr aint2long;

    const Ptr afloat2int;
    const Ptr aint2float;

    const Ptr achar2int;
    const Ptr aint2char;

    const Ptr achar2long;
    const Ptr along2char;

    Ptr populateContext(const Ptr &a) const;
};

} //namespaces
