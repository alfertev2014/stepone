#pragma once

#include "core_defines.h"

#include "dbg.h"

class Ob;

class Pair;
class Atom;
class Lazy;
class Label;

class Symbol;
class Const;

class Macro;
class Evaluator;
class BaseMacro;
class Closure;
class MacroClosure;
class CurrentContext;
class ValueBase;

class TypeInfoBase;

template <class T>
class TypeInfo;

class Ob {
    int refcount;
protected:
    TypeFlags typeFlags;
public:
    class Ptr {
        Ob * ob;
        inline static void incRefCount(Ob * ob) {if(ob != 0) ob->refcount++; else {DBG("ob == 0"); throw SemanticError();}}
        inline static void decRefCount(Ob * ob) {
            if(ob == 0) return;
            ob->refcount--;
            if(ob->refcount == 0)
                delete ob;
        }
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
    Atom * asAtom() {return typeFlags.obType == TypeFlags::Atom ? reinterpret_cast<Atom*>(this) : 0;}
    Lazy * asLazy() {return typeFlags.obType == TypeFlags::Lazy ? reinterpret_cast<Lazy*>(this) : 0;}
    Pair * asPair() {return typeFlags.obType == TypeFlags::Pair ? reinterpret_cast<Pair*>(this) : 0;}
    Label * asLabel() {return typeFlags.obType == TypeFlags::Label ? reinterpret_cast<Label*>(this) : 0;}

    Symbol * asSymbol() {return typeFlags.atomType == TypeFlags::Symbol ? reinterpret_cast<Symbol*>(this) : 0;}
    Const * asConst() {return typeFlags.atomType == TypeFlags::Const ? reinterpret_cast<Const*>(this) : 0;}

    Macro * asMacro() {return typeFlags.constType == TypeFlags::Macro ? reinterpret_cast<Macro*>(this) : 0;}
    ValueBase * asValue() {return typeFlags.constType == TypeFlags::ValueBase ? reinterpret_cast<ValueBase*>(this) : 0;}

    Evaluator * asEvaluator() {return typeFlags.macroValueType == TypeFlags::Evaluator ? reinterpret_cast<Evaluator*>(this) : 0;}
    BaseMacro * asBaseMacro() {return typeFlags.macroValueType == TypeFlags::BaseMacro ? reinterpret_cast<BaseMacro*>(this) : 0;}
    MacroClosure * asMacroClosure() {return typeFlags.macroValueType == TypeFlags::MacroClosure ? reinterpret_cast<MacroClosure*>(this) : 0;}
    CurrentContext * asCurrentContext() {return typeFlags.macroValueType == TypeFlags::CurrentContext ? reinterpret_cast<CurrentContext*>(this) : 0;}

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
};



class TypeInfoBase {
public:
    TypeInfoBase();
    const Ob::Ptr type_id;
};

template <class T>
class TypeInfo : public TypeInfoBase {
public:
    static const TypeInfo<T> instance;
};

class Pair : public Ob {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Pair>::instance;}
private:
    Ptr pcar;
    Ptr pcdr;
public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : pcar(_pcar), pcdr(_pcdr) {
        typeFlags.obType = TypeFlags::Pair;
    }

    Ptr car() {return pcar;}
    Ptr cdr() {return pcdr;}

    Ptr eval(const Ptr & a) {return pcar->eval(a)->apply(pcdr, a);}
};

class Atom : public Ob {
public:
    Atom(){
        typeFlags.obType = TypeFlags::Atom;
    }
    virtual ~Atom() {}
};

class Context {
    Context(){}
public:
    static Ob::Ptr make(const Ob::Ptr & _s, const Ob::Ptr & _e, const Ob::Ptr & _next) {
        return new Pair(new Pair(_s, _e), _next);
    }
};

class Lazy : public Ob {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Lazy>::instance;}
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
    Lazy(const Ptr & _e, const Ptr & _a)
        : e(_e), a(_a), ready(false) {
        typeFlags.obType = TypeFlags::Lazy;
    }

    Ptr car() {evw(); return e->car();}
    Ptr cdr() {evw(); return e->cdr();}

    Ptr eval(const Ptr &a) {evw(); return e->eval(a);}
    Ptr apply(const Ptr &p, const Ptr &a) {
        evw(); return e->apply(p, a);
    }
    Ptr unlazy() {evw(); return e;}
};

class Label : public Ob {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Label>::instance;}
private:
    const Ptr * pa;
    Ob * v;

    Label(Ob * _v, const Ptr * _a) : v(_v), pa(_a) {
        typeFlags.obType = TypeFlags::Label;
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
        Ptr res = e->eval(Context::make(f, lbl, a));
        l->v = res.getPointer();
        l->pa = 0;
        return res;
    }

    Ptr car() {return ptr()->car();}
    Ptr cdr() {return ptr()->cdr();}

    Ptr eval(const Ptr &a) {return ptr()->eval(a);}
    Ptr apply(const Ptr &p, const Ptr &a) {return ptr()->apply(p, a);}
    Ptr unlazy() {return ptr()->unlazy();}
};


class Symbol : public Atom {
public:
    const TypeInfoBase * getTypeInfo() const {return &TypeInfo<Symbol>::instance;}
public:
    Symbol() : Atom() {
        typeFlags.atomType = TypeFlags::Symbol;
    }
    Ptr eval(const Ptr & a) {
        Ptr p = a;
        while(!(p == anil)) {
            Ptr pair = p->car();
            if(pair->car().getPointer() == this)
                return pair->cdr();
            p = p->cdr();
        }
        DBG("Unknown symbol");
        throw SemanticError();
    }
};

class Const : public Atom {
public:
    Const() : Atom() {
        typeFlags.atomType = TypeFlags::Const;
    }
    virtual ~Const() {}
    Ptr eval(const Ptr &a) {return this;}
};

template <class T>
const TypeInfo<T> TypeInfo<T>::instance;

inline bool operator ==(const Ob * const ob, const Ob::Ptr & p) {return ob == p.ob;}



