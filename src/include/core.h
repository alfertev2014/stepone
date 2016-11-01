#pragma once

#include "type_flags.h"

#include "dbg.h"


class SemanticError {};

class TypeInfoBase;

class Ptr;

class Ob {
    friend class Ptr;
    int refcount;
protected:
    TypeFlags typeFlags;
public:
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
    bool is() const;
    template <class T>
    T * cast();
};

class Ptr {
    Ob * ob;
    inline static void incRefCount(Ob * ob);
    inline static void decRefCount(Ob * ob);
public:
    Ptr() : ob(Ob::anil.ob) {incRefCount(ob);}
    Ptr(Ob * _ob) : ob(_ob) {incRefCount(ob);}
    Ptr(const Ptr & _ob) : ob(_ob.ob) {incRefCount(ob);}
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
    
    Ptr car() const;
    Ptr cdr() const;

    Ptr eval(const Ptr & a) const;
    Ptr apply(const Ptr & p, const Ptr & a) const;
    Ptr unlazy() const;
    Ptr assoc(const Ptr & s) const;

    Ptr typeId() const;
    
    template <class T>
    T * as() const;
    template <class T>
    bool is() const;
    template <class T>
    T * cast() const;

    Ob * getPointer() const {return ob;}
};

inline void Ptr::incRefCount(Ob *ob) {
    if(ob != 0)
        ob->refcount++;
    else {
        DBG("ob == 0");
        throw SemanticError();
    }
}

inline void Ptr::decRefCount(Ob *ob) {
    if(ob == 0) return;
    ob->refcount--;
    if(ob->refcount == 0)
        delete ob;
}

inline Ptr Ptr::car() const
{
    return ob->car();
}

inline Ptr Ptr::cdr() const
{
    return ob->cdr();
}

inline Ptr Ptr::eval(const Ptr &a) const
{
    return ob->eval(a);
}

inline Ptr Ptr::apply(const Ptr &p, const Ptr &a) const
{
    return ob->apply(p, a);
}

inline Ptr Ptr::unlazy() const
{
    return ob->unlazy();
}

inline Ptr Ptr::assoc(const Ptr &s) const
{
    return ob->assoc(s);
}



inline bool operator ==(const Ob * const ob, const Ptr & p) {return ob == p.ob;}

