#pragma once

#include "dbg.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class Pair;
class Atom;
class Lazy;
class Label;
class Context;

class Symbol;
class Const;

class Macro;
class Evaluator;
class BaseMacro;
class UserMacro;
class Function;
class BaseFunction;
class Closure;
class Value;

template <class T>
class TypeInfo;

class SemanticError {};

class Ob {
    int refcount;

public: // static
    class Ptr {
        Ob * ob;
    public:
        Ptr() : ob(Ob::anil.ob) {if(ob != 0) ob->refcount++;}
        Ptr(Ob * _ob) : ob(_ob) {if(ob != 0) ob->refcount++;}
        Ptr(const Ob::Ptr & _ob) : ob(_ob.ob) {if(ob != 0) ob->refcount++; else {DBG("ob == 0"); throw SemanticError();}}
        ~Ptr() {if(ob == 0) return; ob->refcount--; if(ob->refcount == 0) delete ob;}

        bool operator == (const Ptr & p) const {return p.ob == ob;}
        bool operator ==(const Ob * const p) const {return ob == p;}
        friend bool operator ==(const Ob * const ob, const Ptr & p);

        Ptr & operator=(const Ptr & p) {return this->operator=(p.ob);}

        Ptr & operator=(Ob * _ob) {
            if(_ob == ob) return *this;
            if(_ob != 0)
                _ob->refcount++;
            if(ob != 0) {
                ob->refcount--;
                if(ob->refcount == 0)
                    delete ob;
            }
            ob = _ob;
            return *this;
        }

        Ob * operator -> () const {return ob;}

        Ob * getPointer() { return ob;}
    };

    static const Ptr anil;
    static const Ptr at;
    static const Ptr aif;
    static const Ptr aquote;
    static const Ptr alambda;
    static const Ptr alet;
    static const Ptr alazy;
    static const Ptr aunlazy;
    static const Ptr alabel;
    static const Ptr amacro;
    static const Ptr atry;
    static const Ptr aeval;
    static const Ptr agensym;

public:
    Ob() : refcount(0) {}
    virtual ~Ob() {}

    virtual Ptr car() {DBG("throw car "); throw SemanticError();}
    virtual Ptr cdr() {DBG("throw cdr "); throw SemanticError();}

    virtual Ptr eval(const Ptr & a) {throw SemanticError();}
    virtual Ptr apply(const Ptr & p, const Ptr & a) {
        if(p == Ob::anil) return this;
        DBG("apply of not applyable"); throw SemanticError();
    }
    virtual Ptr unlazy() {return this;}
    virtual Ptr assoc(const Ptr & s) const {DBG("throw assoc "); throw SemanticError();}

    //Методы для определения типа
    virtual Atom * asAtom() {return 0;}
    virtual Lazy * asLazy() {return 0;}
    virtual Pair * asPair() {return 0;}
    virtual Label * asLabel() {return 0;}
    virtual Context * asContext() {return 0;}

    virtual Symbol * asSymbol() {return 0;}
    virtual Const * asConst() {return 0;}

    virtual Macro * asMacro() {return 0;}
    virtual Evaluator * asEvaluator() {return 0;}
    virtual BaseMacro * asBaseMacro() {return 0;}
    virtual UserMacro * asUserMacro() {return 0;}

    virtual Function * asFunction() {return 0;}
    virtual BaseFunction * asBaseFunction() {return 0;}
    virtual Closure * asClosure() {return 0;}
    virtual Value * asValue() {return 0;}

    virtual Ptr getTypeId() const = 0;

    template <class T>
    T * as() {return TypeInfo<T>::type_id == getTypeId() ? dynamic_cast<T*>(this) : 0;}

    template <class T>
    bool is() const {return TypeInfo<T>::type_id == getTypeId();}

    template <class T>
    T * cast() {
        if(TypeInfo<T>::type_id == getTypeId())
            return dynamic_cast<T*>(this);
        DBG("error cast"); throw SemanticError();
    }

    // Методы для отладки
    virtual string toString() const {return "{ob}";}
    virtual string typeToString() const {return "Ob";}
};

template <class T>
class TypeInfo {
public:
    static const Ob::Ptr type_id;
};

class Pair : public Ob {
public:
    Ptr getTypeId() const {return TypeInfo<Pair>::type_id;}
    static string getTypeString() {return "Pair";}
    string typeToString() const {return getTypeString();}
private:
    Ptr pcar;
    Ptr pcdr;
public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : pcar(_pcar), pcdr(_pcdr) {}

    Pair * asPair() {return this;}

    Ptr car() {return pcar;}
    Ptr cdr() {return pcdr;}

    Ptr eval(const Ptr & a) {return pcar->eval(a)->apply(pcdr, a);}

    string toString() const {
        if(this == pcar || this == pcdr) {  DBG("car==cdr"); throw SemanticError();}
        string res = "(" + pcar->toString();
        Ptr p = pcdr;
        int k = 4;
        while(p->asPair()) {
            if(k <= 0) {
                res += " ...";
                return res + ")";
            }
            res += " " + p->car()->toString();
            p = p->cdr();
            k--;
        }
        if(!(p == Ob::anil))
            res += " . " + p->toString();
        return res + ")";
    }
};

class Atom : public Ob {
public:
    virtual ~Atom() {}

    Atom * asAtom() {return this;}
};

class Context : public Ob {
public:
    Ptr getTypeId() const {return TypeInfo<Context>::type_id;}
    static string getTypeString() {return "Context";}
    string typeToString() const {return getTypeString();}
private:
    Ptr s;
    Ptr e;
    Ptr next;
public:
    Context(const Ptr & _s, const Ptr & _e, const Ptr & _next) : s(_s), e(_e), next(_next) {}

    Ptr getSymbol() const {return s;}
    Ptr getValue() const {return e;}
    Ptr getNext() const {return next;}

    void setSymbol(const Ptr& _s) {s = _s;}
    void setValue(const Ptr& _e) {e = _e;}

    Ptr assoc(const Ptr & _s) const {
        if(s == _s) return e;
        Context * p = next->asContext();
        while(p) {
            if(p->s == _s) return p->e;
            p = p->next->asContext();
        }
        DBG("Unknown symbol");
        throw SemanticError();
    }

    virtual Context * asContext() {return this;}

    string toString() const {
        Context * ctx = next->asContext();
        string res = s->toString() + " = " + e->toString();
        int k = 4;
        while(ctx != 0) {
            if(k <= 0) {
                res += " ...";
                return res;
            }
            res += ", " + ctx->s->toString() + " = " + ctx->e->toString();
            ctx = ctx->next->asContext();
            k--;
        }
        return res;
    }
};

class Lazy : public Ob {
public:
    Ptr getTypeId() const {return TypeInfo<Lazy>::type_id;}
    static string getTypeString() {return "Lazy";}
    string typeToString() const {return getTypeString();}
private:
    Ptr e;
    Ptr a;
    bool ready;

    void ev() {
        if(!ready) {
            e = e->eval(a);
            ready = true;
            a = Ob::anil;
        }
    }

    void evw() {
        ev();
        Lazy * l = e->asLazy();
        while(l != 0) {
            l->ev();
            e = l->e;
            l = e->asLazy();
        }
    }

public:
    Lazy(const Ptr & _e, const Ptr & _a) : e(_e), a(_a), ready(false) {}

    Ptr car() {evw(); return e->car();}
    Ptr cdr() {evw(); return e->cdr();}

    Lazy * asLazy() {return this;}

    Ptr eval(const Ptr &a) {evw(); return e->eval(a);}
    Ptr apply(const Ptr &p, const Ptr &a) {
        if(p == Ob::anil) return this;
        evw(); return e->apply(p, a);
    }
    Ptr unlazy() {evw(); return e;}

    string toString() const {return "{# " + e->toString() + " | " + (ready ? "ready" : a->toString()) + "}";}
};

class Label : public Ob {
public:
    Ptr getTypeId() const {return TypeInfo<Label>::type_id;}
    static string getTypeString() {return "Label";}
    string typeToString() const {return getTypeString();}
private:
    Ob * v;

    Label() {
        DBG("Label created");
    }

    ~Label() {
        DBG("Label destroyed");
    }

public:
    static Ptr loop(const Ptr & f, const Ptr & e, const Ptr & a) {
        Label * l = new Label();
        Ptr lbl = l;
        Ptr res = e->eval(new Context(f, lbl, a));
        l->v = res.getPointer();
        return res;
    }

    Ptr car() {return v->car();}
    Ptr cdr() {return v->cdr();}

    Ptr eval(const Ptr &a) {return v->eval(a);}
    Ptr apply(const Ptr &p, const Ptr &a) {return p == Ob::anil ? this : v->apply(p, a);}
    Ptr unlazy() {return v->unlazy();}

    Label * asLabel() {return this;}

    string toString() const {return "{@ " + v->toString() + "}";}
};


class Symbol : public Atom {
public:
    Ptr getTypeId() const {return TypeInfo<Symbol>::type_id;}
    static string getTypeString() {return "Symbol";}
    string typeToString() const {return getTypeString();}
public:
    Ptr eval(const Ptr & a) {return a->assoc(this);}

    Symbol * asSymbol() {return this;}

    string toString() const {
        if(this == Ob::anil) return "()";
        else if(this == Ob::at) return "t";
        else if(this == Ob::alambda) return "\\";
        else if(this == Ob::alet) return ">-";
        else if(this == Ob::aquote) return "\'";
        else if(this == Ob::aeval) return "~";
        else if(this == Ob::alazy) return "#";
        else if(this == Ob::aunlazy) return "$";
        else if(this == Ob::alabel) return "@";
        else if(this == Ob::aif) return "?";
        else if(this == Ob::atry) return "|";
        else {
            stringstream ss;
            ss << "s" << (void *)this;
            return ss.str();
        }
    }
};

class Const : public Atom {
public:
    virtual ~Const() {}
    Const * asConst() {return this;}

    Ob::Ptr eval(const Ptr &a) {return this;}
};


class Macro : public Const {
public:
    virtual ~Macro() {}
    Macro * asMacro() {return this;}
};

class Evaluator : public Macro {
public:
    Ptr getTypeId() const {return TypeInfo<Evaluator>::type_id;}
    static string getTypeString() {return "Evaluator";}
    string typeToString() const {return getTypeString();}
private:
    Ptr a;
public:
    static const Ptr eempty;

    Evaluator(Ptr _a) : a(_a) {}

    Ptr getContext() const {return a;}

    Ptr apply(const Ptr &p, const Ptr &a) {return p->eval(a)->eval(this->a);}

    Evaluator * asEvaluator() {return this;}
};

class BaseMacro : public Macro {
public:
    virtual ~BaseMacro(){}
    BaseMacro * asBaseMacro() {return this;}
};

class UserMacro : public Macro {
public:
    Ptr getTypeId() const {return TypeInfo<UserMacro>::type_id;}
    static string getTypeString() {return "UserMacro";}
    string typeToString() const {return getTypeString();}
private:
    Ptr sa;
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    UserMacro(const Ptr & _sa, const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : sa(_sa), sp(_sp), e(_e), a(_a) {}

    virtual ~UserMacro(){}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return e->eval(new Context(sp, p, new Context(sa, new Evaluator(a), this->a)));
    }

    UserMacro * asUserMacro() {return this;}

    string toString() const {return "{% " + sa->toString() + ", " + sp->toString() + " . " + e->toString() + " | " + a->toString() + "}";}
};

class Function : public Macro {
protected:
    virtual Ob::Ptr applyX(const Ob::Ptr & x) = 0;
public:
    virtual ~Function() {}
    Function * asFunction() {return this;}

    Ptr apply(const Ptr &p, const Ptr &a) {
        if(p == Ob::anil) return this;
        Ptr e = applyX(p->car()->eval(a));
        Ob::Ptr p1 = p->cdr();
        while(!(p1 == Ob::anil)) {
            Function * f = e->asFunction();
            if(f == 0) {
                return e->apply(p1, a);
            } else {
                e = f->applyX(p1->car()->eval(a));
                p1 = p1->cdr();
            }
        }
        return e;
    }
};


class BaseFunction : public Function {
public:
    virtual ~BaseFunction() {}
    virtual BaseFunction * asBaseFunction() {return this;}

    string toString() const {return "{BaseFunction}";}
};


class Closure : public Function {
public:
    Ptr getTypeId() const {return TypeInfo<Closure>::type_id;}
    static string getTypeString() {return "Closure";}
    string typeToString() const {return getTypeString();}
private:
    Ob::Ptr x;
    Ob::Ptr e;
    Ob::Ptr a;
protected:
    Ob::Ptr applyX(const Ptr &x) {return e->eval(new Context(this->x, x, a));}
public:
    Closure(const Ob::Ptr & _x, const Ob::Ptr & _e, const Ob::Ptr & _a)
        : x(_x), e(_e), a(_a) {}

    Closure * asClosure() {return this;}

    string toString() const {return "{\\ " + x->toString() + " . " + e->toString() + " | " + a->toString() + "}";}
};

class Value : public Const {
public:
    virtual ~Value() {}
    Value * asValue() {return this;}

    string toString() const {return "{Value}";}
};

template <class T>
const Ob::Ptr TypeInfo<T>::type_id(new Symbol);
