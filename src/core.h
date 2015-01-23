#pragma once

#include "dbg.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Ob;

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
class Closure;
class MacroClosure;
class CurrentContext;
class Value;

class TypeInfoBase;

template <class T>
class TypeInfo;

class SemanticError {};

class Ob {
    int refcount;

public: // static
    class Ptr {
        Ob * ob;
        inline static void incRefCount(Ob * ob) {if(ob != 0) ob->refcount++; else {DBG("ob == 0"); throw SemanticError();}}
        inline static void decRefCount(Ob * ob) {if(ob == 0) return; ob->refcount--; if(ob->refcount == 0) delete ob;}
    public:
        Ptr() : ob(Ob::anil.ob) {incRefCount(ob);}
        Ptr(Ob * _ob) : ob(_ob) {incRefCount(ob);}
        Ptr(const Ob::Ptr & _ob) : ob(_ob.ob) {incRefCount(ob);}
        Ptr(bool b) : ob(b ? Ob::at.ob : Ob::anil.ob) {incRefCount(ob);}
        ~Ptr() {decRefCount(ob);}

        bool operator == (const Ptr & p) const {return p.ob == ob;}
        bool operator ==(const Ob * const p) const {return ob == p;}
        friend bool operator ==(const Ob * const ob, const Ptr & p);

        Ptr & operator=(const Ptr & p) {return this->operator=(p.ob);}
        Ptr & operator=(Ob * _ob) {
            if(_ob != ob) {
                // don't change order
                incRefCount(_ob);
                decRefCount(ob);
                ob = _ob;
            }
            return *this;
        }

        Ob * operator -> () const {return ob;}
        Ob * getPointer() const {return ob;}
    };

    static const Ptr anil;
    static const Ptr at;

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
    virtual Closure * asClosure() {return 0;}
    virtual MacroClosure * asMacroClosure() {return 0;}
    virtual CurrentContext * asCurrentContext() {return 0;}
    virtual Value * asValue() {return 0;}

    virtual const TypeInfoBase * getTypeInfo() const = 0;

    template <class T>
    T * as() {return &TypeInfo<T>::instance == getTypeInfo() ? dynamic_cast<T*>(this) : 0;}

    template <class T>
    bool is() const {return &TypeInfo<T>::instance == getTypeInfo();}

    template <class T>
    T * cast() {
        if(&TypeInfo<T>::instance == getTypeInfo())
            return dynamic_cast<T*>(this);
        DBG("error cast"); throw SemanticError();
    }

    // Методы для отладки
    string typeToString() const;
    virtual string toString() const {return "{" + typeToString() + "}";}
};

class TypeInfoBase {
public:
    TypeInfoBase();
    const Ob::Ptr type_id;
    virtual string getTypeString() const = 0;
};

template <class T>
class TypeInfo : public TypeInfoBase {
public:
    static const TypeInfo<T> instance;
    string getTypeString() const {return T::getTypeString();}
};

class Pair : public Ob {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Pair>::instance;}
    static string getTypeString() {return "Pair";}
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
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Context>::instance;}
    static string getTypeString() {return "Context";}
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
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Lazy>::instance;}
    static string getTypeString() {return "Lazy";}
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
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Label>::instance;}
    static string getTypeString() {return "Label";}
private:
    const Ptr * pa;
    Ob * v;

    Label(Ob * _v, const Ptr * _a) : v(_v), pa(_a) {
        DBG("Label created");
    }

    ~Label() {
        DBG("Label destroyed");
    }

    Ptr ptr() {
        if(pa) {
            return v->eval(*pa);
        }
        return v;
    }

public:
    static Ptr loop(const Ptr & f, const Ptr & e, const Ptr & a) {
        Label * l = new Label(e.getPointer(), &a);
        Ptr lbl = l;
        Ptr res = e->eval(new Context(f, lbl, a));
        l->v = res.getPointer();
        l->pa = 0;
        return res;
    }

    Ptr car() {return ptr()->car();}
    Ptr cdr() {return ptr()->cdr();}

    Ptr eval(const Ptr &a) {return ptr()->eval(a);}
    Ptr apply(const Ptr &p, const Ptr &a) {return p == Ob::anil ? this : ptr()->apply(p, a);}
    Ptr unlazy() {return ptr()->unlazy();}

    Label * asLabel() {return this;}

    string toString() const {return "{@ " + (!pa ? v->toString() : "") + "}";}
};


class Symbol : public Atom {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Symbol>::instance;}
    static string getTypeString() {return "Symbol";}
public:
    Ptr eval(const Ptr & a) {return a->assoc(this);}

    Symbol * asSymbol() {return this;}

    string toString() const {
        if(this == Ob::anil) return "()";
        else if(this == Ob::at) return "t";
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
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Evaluator>::instance;}
    static string getTypeString() {return "Evaluator";}
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

class Closure : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Closure>::instance;}
    static string getTypeString() {return "Closure";}
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    Closure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : sp(_sp), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a) {
        if(p == Ob::anil)
            return this;
        return e->eval(new Context(sp, p->car()->eval(a), this->a))->apply(p->cdr(), a);
    }

    Closure * asClosure() {return this;}

    string toString() const {return "{\\ " + sp->toString() + " . " + e->toString() + " | " + a->toString() + "}";}
};

class MacroClosure : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<MacroClosure>::instance;}
    static string getTypeString() {return "MacroClosure";}
private:
    Ptr sp;
    Ptr e;
    Ptr a;
public:
    MacroClosure(const Ptr & _sp, const Ptr & _e, const Ptr & _a)
        : sp(_sp), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return e->eval(new Context(sp, p, this->a));
    }

    MacroClosure * asMacroClosure() {return this;}

    string toString() const {return "{% " + sp->toString() + " . " + e->toString() + " | " + a->toString() + "}";}
};

class CurrentContext : public Macro {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<CurrentContext>::instance;}
    static string getTypeString() {return "CurrentContext";}
private:
    Ptr sa;
    Ptr e;
    Ptr a;
public:
    CurrentContext(const Ptr & _sa, const Ptr & _e, const Ptr & _a)
        : sa(_sa), e(_e), a(_a) {}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return e->eval(new Context(sa, new Evaluator(a), this->a))->apply(p, this->a);
    }

    CurrentContext * asCurrentContext() {return this;}

    string toString() const {return "{% " + sa->toString() + " . " + e->toString() + " | " + a->toString() + "}";}
};

class Value : public Const {
public:
    virtual ~Value() {}
    Value * asValue() {return this;}
};

template <class T>
const TypeInfo<T> TypeInfo<T>::instance;
