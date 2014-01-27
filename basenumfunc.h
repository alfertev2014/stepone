#ifndef BASETYPES_H
#define BASETYPES_H

#include "core.h"

class BaseNumFunc
{
    BaseNumFunc(){}
public:
    static const Ob::Ptr fintPlus;
    static const Ob::Ptr fintMinus;
    static const Ob::Ptr fintProduct;
    static const Ob::Ptr fintDivision;
    static const Ob::Ptr fintMod;
    static const Ob::Ptr fintp;
    static const Ob::Ptr fintEql;
    static const Ob::Ptr fintNE;
    static const Ob::Ptr fintGT;
    static const Ob::Ptr fintLT;
    static const Ob::Ptr fintGE;
    static const Ob::Ptr fintLE;

    static const Ob::Ptr ffloatPlus;
    static const Ob::Ptr ffloatMinus;
    static const Ob::Ptr ffloatProduct;
    static const Ob::Ptr ffloatDivision;
    static const Ob::Ptr ffloatp;
    static const Ob::Ptr ffloatEql;
    static const Ob::Ptr ffloatNE;
    static const Ob::Ptr ffloatGT;
    static const Ob::Ptr ffloatLT;
    static const Ob::Ptr ffloatGE;
    static const Ob::Ptr ffloatLE;

    static const Ob::Ptr ffloat2int;
    static const Ob::Ptr fint2float;
};
#endif // BASETYPES_H
