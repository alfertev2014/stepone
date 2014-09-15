#pragma once

#include "core.h"

class FPairP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FPairP>::type_id;}
    static string getTypeString() {return "FPairP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asPair() ? Ob::at : Ob::anil;}

    string toString() const {return "FPairP";}
};

class FLazyP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FLazyP>::type_id;}
    static string getTypeString() {return "FLazyP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asLazy() ? Ob::at : Ob::anil;}

    string toString() const {return "FLazyP";}
};

class FLabelP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FLabelP>::type_id;}
    static string getTypeString() {return "FLabelP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asLabel() ? Ob::at : Ob::anil;}

    string toString() const {return "FLabelP";}
};

class FContextP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FContextP>::type_id;}
    static string getTypeString() {return "FContextP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asContext() ? Ob::at : Ob::anil;}

    string toString() const {return "FContextP";}
};

class FAtomP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FAtomP>::type_id;}
    static string getTypeString() {return "FAtomP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asAtom() ? Ob::at : Ob::anil;}

    string toString() const {return "FAtomP";}
};

class FSymbolP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FSymbolP>::type_id;}
    static string getTypeString() {return "FSymbolP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asSymbol() ? Ob::at : Ob::anil;}

    string toString() const {return "FSymbolP";}
};

class FConstP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FConstP>::type_id;}
    static string getTypeString() {return "FConstP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asConst() ? Ob::at : Ob::anil;}

    string toString() const {return "FConstP";}
};

class FMacroP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FMacroP>::type_id;}
    static string getTypeString() {return "FMacroP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asMacro() ? Ob::at : Ob::anil;}

    string toString() const {return "FMacroP";}
};

class FEvaluatorP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FEvaluatorP>::type_id;}
    static string getTypeString() {return "FEvaluatorP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asEvaluator() ? Ob::at : Ob::anil;}

    string toString() const {return "FEvaluatorP";}
};

class FBaseMacroP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FBaseMacroP>::type_id;}
    static string getTypeString() {return "FBaseMacroP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asBaseMacro() ? Ob::at : Ob::anil;}

    string toString() const {return "FBaseMacroP";}
};

class FUserMacroP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FUserMacroP>::type_id;}
    static string getTypeString() {return "FUserMacroP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asMacroClosure() ? Ob::at : Ob::anil;}

    string toString() const {return "FUserMacroP";}
};

class FSpecTypeP : public BaseMacro {
public:
    Ptr getTypeId() const {return TypeInfo<FSpecTypeP>::type_id;}
    static string getTypeString() {return "FSpecTypeP";}
    string typeToString() const {return getTypeString();}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->asValue() ? Ob::at : Ob::anil;}

    string toString() const {return "FSpecTypeP";}
};


class BaseTypePredicates {
    BaseTypePredicates(){}
public:
    static const Ob::Ptr fpairp;
    static const Ob::Ptr flazyp;
    static const Ob::Ptr flabelp;
    static const Ob::Ptr fcontextp;
    static const Ob::Ptr fatomp;
    static const Ob::Ptr fsymbolp;
    static const Ob::Ptr fconstp;
    static const Ob::Ptr fmacrop;
    static const Ob::Ptr fevalp;
    static const Ob::Ptr fbasemacrop;
    static const Ob::Ptr fusermacrop;
    static const Ob::Ptr fspectypep;
};
