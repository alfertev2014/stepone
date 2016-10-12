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
    virtual ~Ob();

    virtual Ptr car();
    virtual Ptr cdr();

    virtual Ptr eval(const Ptr & a);
    virtual Ptr apply(const Ptr & p, const Ptr & a);
    virtual Ptr unlazy();
    virtual Ptr assoc(const Ptr & s) const;

    virtual const TypeInfoBase * getTypeInfo() const = 0;

    template <class T>
    T * as();

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
    const TypeInfoBase * getTypeInfo() const;
private:
    Ptr pcar;
    Ptr pcdr;
public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : pcar(_pcar), pcdr(_pcdr) {
        typeFlags.obType = TypeFlags::Pair;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr & a);
};

class Atom : public Ob {
public:
    Atom() {
        typeFlags.obType = TypeFlags::Atom;
    }
    virtual ~Atom();
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
    const TypeInfoBase * getTypeInfo() const;
private:
    Ptr e;
    Ptr a;

    void ev();
    void evw();

public:
    Lazy(const Ptr & _e, const Ptr & _a)
        : e(_e), a(_a) {
        typeFlags.obType = TypeFlags::Lazy;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};

class Label : public Ob {
public:
    const TypeInfoBase * getTypeInfo() const;
private:
    const Ptr * pa;
    Ob * v;

    Label(Ob * _v, const Ptr * _a) : v(_v), pa(_a) {
        typeFlags.obType = TypeFlags::Label;
    }

    Ptr ptr();

public:
    static Ptr loop(const Ptr & f, const Ptr & e, const Ptr & a) {
        Label * l = new Label(e.getPointer(), &a);
        Ptr lbl = l;
        Ptr res = e->eval(Context::make(f, lbl, a));
        l->v = res.getPointer();
        l->pa = 0;
        return res;
    }

    Ptr car();
    Ptr cdr();

    Ptr eval(const Ptr &a);
    Ptr apply(const Ptr &p, const Ptr &a);
    Ptr unlazy();
};


class Symbol : public Atom {
public:
    const TypeInfoBase * getTypeInfo() const;
public:
    Symbol() : Atom() {
        typeFlags.atomType = TypeFlags::Symbol;
    }
    Ptr eval(const Ptr & a);
};

class Const : public Atom {
public:
    Const() : Atom() {
        typeFlags.atomType = TypeFlags::Const;
    }
    virtual ~Const();
    Ptr eval(const Ptr &a);
};

template <class T>
const TypeInfo<T> TypeInfo<T>::instance;

inline bool operator ==(const Ob * const ob, const Ob::Ptr & p) {return ob == p.ob;}

template <class T>
T * Ob::as() {return &TypeInfo<T>::instance == getTypeInfo() ? dynamic_cast<T*>(this) : 0;}

template<>
Atom *Ob::as<Atom>();

template<>
Lazy *Ob::as<Lazy>();

template<>
Pair *Ob::as<Pair>();

template<>
Label *Ob::as<Label>();

template<>
Symbol *Ob::as<Symbol>();

template<>
Const *Ob::as<Const>();

template<>
Macro *Ob::as<Macro>();

template<>
ValueBase *Ob::as<ValueBase>();

template<>
Evaluator *Ob::as<Evaluator>();

template<>
BaseMacro *Ob::as<BaseMacro>();

template<>
MacroClosure *Ob::as<MacroClosure>();

template<>
CurrentContext *Ob::as<CurrentContext>();
