#pragma once

#include <ptr.h>

namespace stepone::objects {

class BaseNumFunc {
    BaseNumFunc();
public:
    static const BaseNumFunc &inst();

    const Ptr aintNeg;
    const Ptr aintPlus;
    const Ptr aintMinus;
    const Ptr aintProduct;
    const Ptr aintDivision;
    const Ptr aintMod;
    const Ptr aintp;

    const Ptr aintand;
    const Ptr aintor;
    const Ptr aintxor;
    const Ptr aintnot;

    const Ptr aintshl;
    const Ptr aintshr;

    const Ptr aintEql;
    const Ptr aintNE;
    const Ptr aintGT;
    const Ptr aintLT;
    const Ptr aintGE;
    const Ptr aintLE;

    const Ptr alongp;
    const Ptr alongand;
    const Ptr alongor;
    const Ptr alongxor;
    const Ptr alongnot;

    const Ptr alongEql;
    const Ptr alongNE;
    const Ptr alongGT;
    const Ptr alongLT;
    const Ptr alongGE;
    const Ptr alongLE;

    const Ptr alongshl;
    const Ptr alongshr;

    const Ptr afloatNeg;
    const Ptr afloatPlus;
    const Ptr afloatMinus;
    const Ptr afloatProduct;
    const Ptr afloatDivision;
    const Ptr afloatp;
    const Ptr afloatEql;
    const Ptr afloatNE;
    const Ptr afloatGT;
    const Ptr afloatLT;
    const Ptr afloatGE;
    const Ptr afloatLE;

    const Ptr along2int;
    const Ptr aint2long;

    const Ptr afloat2int;
    const Ptr aint2float;

    const Ptr achar2int;
    const Ptr aint2char;

    const Ptr achar2long;
    const Ptr along2char;

    const Ptr acharp;
    const Ptr acharand;
    const Ptr acharor;
    const Ptr acharxor;
    const Ptr acharnot;

    const Ptr acharshl;
    const Ptr acharshr;

    const Ptr acharEql;
    const Ptr acharNE;
    const Ptr acharGT;
    const Ptr acharLT;
    const Ptr acharGE;
    const Ptr acharLE;

    const Ptr aszi;
    const Ptr aszf;
    const Ptr aszc;
    const Ptr aszu;

    Ptr populateContext(const Ptr &a) const;
};

} //namespaces
