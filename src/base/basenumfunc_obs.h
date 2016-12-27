#pragma once

#include <ob.h>

class BaseNumFunc {
    BaseNumFunc();
public:
    static const BaseNumFunc &inst();

    const Ptr fintNeg;
    const Ptr fintPlus;
    const Ptr fintMinus;
    const Ptr fintProduct;
    const Ptr fintDivision;
    const Ptr fintMod;
    const Ptr fintp;

    const Ptr fintand;
    const Ptr fintor;
    const Ptr fintxor;
    const Ptr fintnot;

    const Ptr fintshl;
    const Ptr fintshr;

    const Ptr fintEql;
    const Ptr fintNE;
    const Ptr fintGT;
    const Ptr fintLT;
    const Ptr fintGE;
    const Ptr fintLE;

    const Ptr flongp;
    const Ptr flongand;
    const Ptr flongor;
    const Ptr flongxor;
    const Ptr flongnot;

    const Ptr flongEql;
    const Ptr flongNE;
    const Ptr flongGT;
    const Ptr flongLT;
    const Ptr flongGE;
    const Ptr flongLE;

    const Ptr flongshl;
    const Ptr flongshr;

    const Ptr ffloatNeg;
    const Ptr ffloatPlus;
    const Ptr ffloatMinus;
    const Ptr ffloatProduct;
    const Ptr ffloatDivision;
    const Ptr ffloatp;
    const Ptr ffloatEql;
    const Ptr ffloatNE;
    const Ptr ffloatGT;
    const Ptr ffloatLT;
    const Ptr ffloatGE;
    const Ptr ffloatLE;

    const Ptr flong2int;
    const Ptr fint2long;

    const Ptr ffloat2int;
    const Ptr fint2float;

    const Ptr fchar2int;
    const Ptr fint2char;

    const Ptr fchar2long;
    const Ptr flong2char;

    const Ptr fcharp;
    const Ptr fcharand;
    const Ptr fcharor;
    const Ptr fcharxor;
    const Ptr fcharnot;

    const Ptr fcharshl;
    const Ptr fcharshr;

    const Ptr fcharEql;
    const Ptr fcharNE;
    const Ptr fcharGT;
    const Ptr fcharLT;
    const Ptr fcharGE;
    const Ptr fcharLE;
};
