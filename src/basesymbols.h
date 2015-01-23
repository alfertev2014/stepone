#pragma once

#include "core.h"

class BaseMacroSymbols {
    BaseMacroSymbols();
public:
    static const BaseMacroSymbols &inst();

    const Ob::Ptr aquote;
    const Ob::Ptr aapply;
    const Ob::Ptr aif;
    const Ob::Ptr alet;
    const Ob::Ptr alazy;
    const Ob::Ptr aunlazy;
    const Ob::Ptr alabel;
    const Ob::Ptr alambda;
    const Ob::Ptr amacro;
    const Ob::Ptr acurctx;
    const Ob::Ptr atry;
    const Ob::Ptr abot;
    const Ob::Ptr agensym;
};

class BaseFuncSymbols {
    BaseFuncSymbols();
public:
    static const BaseFuncSymbols &inst();

    const Ob::Ptr acar;
    const Ob::Ptr acdr;
    const Ob::Ptr acons;
    const Ob::Ptr aeq;
    const Ob::Ptr agettype;
    const Ob::Ptr actxget;
    const Ob::Ptr actxpush;

    const Ob::Ptr aeempty;
};

class BaseTypePredSymbols {
    BaseTypePredSymbols();
public:
    static const BaseTypePredSymbols &inst();

    const Ob::Ptr apairp;
    const Ob::Ptr alazyp;
    const Ob::Ptr alabelp;
    const Ob::Ptr acontextp;
    const Ob::Ptr aatomp;
    const Ob::Ptr asymbolp;
    const Ob::Ptr aconstp;
    const Ob::Ptr amacrop;
    const Ob::Ptr aevalp;
    const Ob::Ptr abasemacrop;
    const Ob::Ptr ausermacrop;
    const Ob::Ptr avaluep;
};

class BaseNumFuncSymbols {
    BaseNumFuncSymbols();
public:
    static const BaseNumFuncSymbols &inst();

    const Ob::Ptr aintNeg;
    const Ob::Ptr aintPlus;
    const Ob::Ptr aintMinus;
    const Ob::Ptr aintProduct;
    const Ob::Ptr aintDivision;
    const Ob::Ptr aintMod;
    const Ob::Ptr aintp;

    const Ob::Ptr aintand;
    const Ob::Ptr aintor;
    const Ob::Ptr aintxor;
    const Ob::Ptr aintnot;

    const Ob::Ptr aintshl;
    const Ob::Ptr aintshr;

    const Ob::Ptr aintEql;
    const Ob::Ptr aintNE;
    const Ob::Ptr aintGT;
    const Ob::Ptr aintLT;
    const Ob::Ptr aintGE;
    const Ob::Ptr aintLE;

    const Ob::Ptr alongp;
    const Ob::Ptr alongand;
    const Ob::Ptr alongor;
    const Ob::Ptr alongxor;
    const Ob::Ptr alongnot;

    const Ob::Ptr alongEql;
    const Ob::Ptr alongNE;
    const Ob::Ptr alongGT;
    const Ob::Ptr alongLT;
    const Ob::Ptr alongGE;
    const Ob::Ptr alongLE;

    const Ob::Ptr alongshl;
    const Ob::Ptr alongshr;

    const Ob::Ptr afloatNeg;
    const Ob::Ptr afloatPlus;
    const Ob::Ptr afloatMinus;
    const Ob::Ptr afloatProduct;
    const Ob::Ptr afloatDivision;
    const Ob::Ptr afloatp;
    const Ob::Ptr afloatEql;
    const Ob::Ptr afloatNE;
    const Ob::Ptr afloatGT;
    const Ob::Ptr afloatLT;
    const Ob::Ptr afloatGE;
    const Ob::Ptr afloatLE;

    const Ob::Ptr along2int;
    const Ob::Ptr aint2long;

    const Ob::Ptr afloat2int;
    const Ob::Ptr aint2float;

    const Ob::Ptr achar2int;
    const Ob::Ptr aint2char;

    const Ob::Ptr achar2long;
    const Ob::Ptr along2char;

    const Ob::Ptr acharp;
    const Ob::Ptr acharand;
    const Ob::Ptr acharor;
    const Ob::Ptr acharxor;
    const Ob::Ptr acharnot;

    const Ob::Ptr acharshl;
    const Ob::Ptr acharshr;

    const Ob::Ptr acharEql;
    const Ob::Ptr acharNE;
    const Ob::Ptr acharGT;
    const Ob::Ptr acharLT;
    const Ob::Ptr acharGE;
    const Ob::Ptr acharLE;

    const Ob::Ptr aszi;
    const Ob::Ptr aszf;
    const Ob::Ptr aszc;
    const Ob::Ptr aszu;
};

class VectorFuncSymbols {
    VectorFuncSymbols();
public:
    static const VectorFuncSymbols &inst();

    const Ob::Ptr avecp;
    const Ob::Ptr amkvec;
    const Ob::Ptr avecclone;
    const Ob::Ptr aveclen;
    const Ob::Ptr avecmid;
    const Ob::Ptr avecslice;
    const Ob::Ptr avecel;
    const Ob::Ptr aveccat;
};

class ByteArrayFuncSymbols {
    ByteArrayFuncSymbols();
public:
    static const ByteArrayFuncSymbols &inst();

    const Ob::Ptr abarrayp;
    const Ob::Ptr abarraylen;
    const Ob::Ptr abarrayclone;
    const Ob::Ptr abarraycmp;
    const Ob::Ptr abarrayncmp;
    const Ob::Ptr abarrayfindch;
    const Ob::Ptr abarrayfind;
    const Ob::Ptr abarraycat;
    const Ob::Ptr abarraymid;
    const Ob::Ptr abarrayslice;

    const Ob::Ptr aserint;
    const Ob::Ptr aserfloat;
    const Ob::Ptr aserchar;

    const Ob::Ptr agetint;
    const Ob::Ptr agetfloat;
    const Ob::Ptr agetchar;
};

class IOFuncSymbols {
    IOFuncSymbols();
public:
    static const IOFuncSymbols &inst();

    const Ob::Ptr ainputp;
    const Ob::Ptr aoutputp;
    const Ob::Ptr aopenin;
    const Ob::Ptr aopenout;
    const Ob::Ptr aread;
    const Ob::Ptr awrite;

    const Ob::Ptr astdin;
    const Ob::Ptr astdout;
    const Ob::Ptr astderr;
};
