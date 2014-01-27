#ifndef TYPEPREDICATES_H
#define TYPEPREDICATES_H

#include "core.h"

class FPairP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isPair() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FPairP";}
};

class FLazyP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isLazy() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FLazyP";}
};

class FLabelP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isLabel() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FLabelP";}
};

class FContextP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isContext() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FContextP";}
};

class FAtomP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isAtom() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FAtomP";}
};

class FSymbolP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isSymbol() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FSymbolP";}
};

class FConstP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isConst() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FConstP";}
};

class FMacroP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isMacro() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FMacroP";}
};

class FBaseMacroP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isBaseMacro() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FBaseMacroP";}
};

class FUserMacroP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isUserMacro() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FUserMacroP";}
};

class FFunctionP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isFunction() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FFunctionP";}
};

class FBaseFunctionP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isBaseFunction() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FBaseFunctionP";}
};

class FClosureP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isClosure() ? Ob::at : Ob::anil;}
public:
    string toString() const {return "FClosureP";}
};

class FSpecTypeP : public BaseFunction {
protected:
    Ob::Ptr applyX(const Ptr &x) {return x->isSpecType() ? Ob::at : Ob::anil;}
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
    static const Ob::Ptr fbasemacrop;
    static const Ob::Ptr fusermacrop;
    static const Ob::Ptr ffunctionp;
    static const Ob::Ptr fbasefunctionp;
    static const Ob::Ptr fclosurep;
    static const Ob::Ptr fspectypep;
};


#endif // TYPEPREDICATES_H
