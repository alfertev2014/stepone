#ifndef TYPEPREDICATES_H
#define TYPEPREDICATES_H

#include "core.h"

class FPairP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FPairP>::type_id;}
    static string getTypeString() {return "FPairP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isPair() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FPairP";}
};

class FLazyP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FLazyP>::type_id;}
    static string getTypeString() {return "FLazyP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isLazy() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FLazyP";}
};

class FLabelP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FLabelP>::type_id;}
    static string getTypeString() {return "FLabelP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isLabel() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FLabelP";}
};

class FContextP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FContextP>::type_id;}
    static string getTypeString() {return "FContextP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isContext() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FContextP";}
};

class FAtomP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FAtomP>::type_id;}
    static string getTypeString() {return "FAtomP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isAtom() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FAtomP";}
};

class FSymbolP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FSymbolP>::type_id;}
    static string getTypeString() {return "FSymbolP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isSymbol() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FSymbolP";}
};

class FConstP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FConstP>::type_id;}
    static string getTypeString() {return "FConstP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isConst() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FConstP";}
};

class FMacroP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FMacroP>::type_id;}
    static string getTypeString() {return "FMacroP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isMacro() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FMacroP";}
};

class FEvaluatorP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FEvaluatorP>::type_id;}
    static string getTypeString() {return "FEvaluatorP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isEvaluator() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FEvaluatorP";}
};

class FBaseMacroP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FBaseMacroP>::type_id;}
    static string getTypeString() {return "FBaseMacroP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isBaseMacro() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FBaseMacroP";}
};

class FUserMacroP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FUserMacroP>::type_id;}
    static string getTypeString() {return "FUserMacroP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isUserMacro() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FUserMacroP";}
};

class FFunctionP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FFunctionP>::type_id;}
    static string getTypeString() {return "FFunctionP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isFunction() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FFunctionP";}
};

class FBaseFunctionP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FBaseFunctionP>::type_id;}
    static string getTypeString() {return "FBaseFunctionP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isBaseFunction() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FBaseFunctionP";}
};

class FClosureP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FClosureP>::type_id;}
    static string getTypeString() {return "FClosureP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isClosure() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FClosureP";}
};

class FSpecTypeP : public BaseFunction {
public:
    Ptr getTypeId() const {return TypeInfo<FSpecTypeP>::type_id;}
    static string getTypeString() {return "FSpecTypeP";}
    string typeToString() const {return getTypeString();}
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isValue() ? Ob::at : Ob::anil;}
public:
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
    static const Ob::Ptr ffunctionp;
    static const Ob::Ptr fbasefunctionp;
    static const Ob::Ptr fclosurep;
    static const Ob::Ptr fspectypep;
};


#endif // TYPEPREDICATES_H
