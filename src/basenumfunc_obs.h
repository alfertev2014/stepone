#pragma once

#include "core.h"

class BaseNumFunc {
    BaseNumFunc();
public:
    static const BaseNumFunc &inst();

    const Ob::Ptr fintNeg;
    const Ob::Ptr fintPlus;
    const Ob::Ptr fintMinus;
    const Ob::Ptr fintProduct;
    const Ob::Ptr fintDivision;
    const Ob::Ptr fintMod;
    const Ob::Ptr fintp;

    const Ob::Ptr fintand;
    const Ob::Ptr fintor;
    const Ob::Ptr fintxor;
    const Ob::Ptr fintnot;

    const Ob::Ptr fintshl;
    const Ob::Ptr fintshr;

    const Ob::Ptr fintEql;
    const Ob::Ptr fintNE;
    const Ob::Ptr fintGT;
    const Ob::Ptr fintLT;
    const Ob::Ptr fintGE;
    const Ob::Ptr fintLE;

    const Ob::Ptr flongp;
    const Ob::Ptr flongand;
    const Ob::Ptr flongor;
    const Ob::Ptr flongxor;
    const Ob::Ptr flongnot;

    const Ob::Ptr flongEql;
    const Ob::Ptr flongNE;
    const Ob::Ptr flongGT;
    const Ob::Ptr flongLT;
    const Ob::Ptr flongGE;
    const Ob::Ptr flongLE;

    const Ob::Ptr flongshl;
    const Ob::Ptr flongshr;

    const Ob::Ptr ffloatNeg;
    const Ob::Ptr ffloatPlus;
    const Ob::Ptr ffloatMinus;
    const Ob::Ptr ffloatProduct;
    const Ob::Ptr ffloatDivision;
    const Ob::Ptr ffloatp;
    const Ob::Ptr ffloatEql;
    const Ob::Ptr ffloatNE;
    const Ob::Ptr ffloatGT;
    const Ob::Ptr ffloatLT;
    const Ob::Ptr ffloatGE;
    const Ob::Ptr ffloatLE;

    const Ob::Ptr flong2int;
    const Ob::Ptr fint2long;

    const Ob::Ptr ffloat2int;
    const Ob::Ptr fint2float;

    const Ob::Ptr fchar2int;
    const Ob::Ptr fint2char;

    const Ob::Ptr fchar2long;
    const Ob::Ptr flong2char;

    const Ob::Ptr fcharp;
    const Ob::Ptr fcharand;
    const Ob::Ptr fcharor;
    const Ob::Ptr fcharxor;
    const Ob::Ptr fcharnot;

    const Ob::Ptr fcharshl;
    const Ob::Ptr fcharshr;

    const Ob::Ptr fcharEql;
    const Ob::Ptr fcharNE;
    const Ob::Ptr fcharGT;
    const Ob::Ptr fcharLT;
    const Ob::Ptr fcharGE;
    const Ob::Ptr fcharLE;
};
