#ifndef BASETYPES_H
#define BASETYPES_H

#include "core.h"

class BaseNumFunc {
    BaseNumFunc(){}
public:
    static const Ob::Ptr fintNeg;
    static const Ob::Ptr fintPlus;
    static const Ob::Ptr fintMinus;
    static const Ob::Ptr fintProduct;
    static const Ob::Ptr fintDivision;
    static const Ob::Ptr fintMod;
    static const Ob::Ptr fintp;

    static const Ob::Ptr fintand;
    static const Ob::Ptr fintor;
    static const Ob::Ptr fintxor;
    static const Ob::Ptr fintnot;

    static const Ob::Ptr fintshl;
    static const Ob::Ptr fintshr;

    static const Ob::Ptr fintEql;
    static const Ob::Ptr fintNE;
    static const Ob::Ptr fintGT;
    static const Ob::Ptr fintLT;
    static const Ob::Ptr fintGE;
    static const Ob::Ptr fintLE;

    static const Ob::Ptr flongp;
    static const Ob::Ptr flongand;
    static const Ob::Ptr flongor;
    static const Ob::Ptr flongxor;
    static const Ob::Ptr flongnot;

    static const Ob::Ptr flongEql;
    static const Ob::Ptr flongNE;
    static const Ob::Ptr flongGT;
    static const Ob::Ptr flongLT;
    static const Ob::Ptr flongGE;
    static const Ob::Ptr flongLE;

    static const Ob::Ptr flongshl;
    static const Ob::Ptr flongshr;

    static const Ob::Ptr ffloatNeg;
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

    static const Ob::Ptr flong2int;
    static const Ob::Ptr fint2long;

    static const Ob::Ptr ffloat2int;
    static const Ob::Ptr fint2float;
};
#endif // BASETYPES_H
