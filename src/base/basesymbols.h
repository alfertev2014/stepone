#pragma once

#include "core.h"

class BaseMacroSymbols {
    BaseMacroSymbols();
public:
    static const BaseMacroSymbols &inst();

    const Ptr aquote;
    const Ptr aapply;
    const Ptr aif;
    const Ptr alet;
    const Ptr alazy;
    const Ptr aunlazy;
    const Ptr alabel;
    const Ptr alambda;
    const Ptr amacro;
    const Ptr acurctx;
    const Ptr atry;
    const Ptr abot;
    const Ptr agensym;
};

class BaseFuncSymbols {
    BaseFuncSymbols();
public:
    static const BaseFuncSymbols &inst();

    const Ptr acar;
    const Ptr acdr;
    const Ptr acons;
    const Ptr aeq;
    const Ptr agettype;
    const Ptr actxget;
    const Ptr actxpush;

    const Ptr aeempty;
};

class BaseTypePredSymbols {
    BaseTypePredSymbols();
public:
    static const BaseTypePredSymbols &inst();

    const Ptr apairp;
    const Ptr alazyp;
    const Ptr alabelp;
    const Ptr aatomp;
    const Ptr asymbolp;
    const Ptr aconstp;
    const Ptr amacrop;
    const Ptr aevalp;
    const Ptr abasemacrop;
    const Ptr ausermacrop;
    const Ptr avaluep;
};

class BaseNumFuncSymbols {
    BaseNumFuncSymbols();
public:
    static const BaseNumFuncSymbols &inst();

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
};

class VectorFuncSymbols {
    VectorFuncSymbols();
public:
    static const VectorFuncSymbols &inst();

    const Ptr avecp;
    const Ptr amkvec;
    const Ptr avecclone;
    const Ptr aveclen;
    const Ptr avecmid;
    const Ptr avecslice;
    const Ptr avecel;
    const Ptr aveccat;
};

class ByteArrayFuncSymbols {
    ByteArrayFuncSymbols();
public:
    static const ByteArrayFuncSymbols &inst();

    const Ptr abarrayp;
    const Ptr abarraylen;
    const Ptr abarrayclone;
    const Ptr abarraycmp;
    const Ptr abarrayncmp;
    const Ptr abarrayfindch;
    const Ptr abarrayfind;
    const Ptr abarraycat;
    const Ptr abarraymid;
    const Ptr abarrayslice;

    const Ptr aserint;
    const Ptr aserfloat;
    const Ptr aserchar;

    const Ptr agetint;
    const Ptr agetfloat;
    const Ptr agetchar;
};

class IOFuncSymbols {
    IOFuncSymbols();
public:
    static const IOFuncSymbols &inst();

    const Ptr ainputp;
    const Ptr aoutputp;
    const Ptr aopenin;
    const Ptr aopenout;
    const Ptr aread;
    const Ptr awrite;

    const Ptr astdin;
    const Ptr astdout;
    const Ptr astderr;
};
