#pragma once

#include "type_flags.h"

#include "dbg.h"


class SemanticError {};

class TypeInfoBase;

class WPtr;
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

class WPtr {
    friend class Ptr;
    Ob * ob;

    WPtr(Ob * _ob) : ob(_ob) {}
public:
    friend bool operator==(const Ob * const & ob, const WPtr & p);
    friend bool operator!=(const Ob * const & ob, const WPtr & p);

    bool operator==(const WPtr & p) const {return ob == p;}
    bool operator!=(const WPtr & p) const {return ob != p;}

    bool operator==(const Ob * const p) const {return ob == p;}
    bool operator!=(const Ob * const p) const {return !(ob == p);}

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
};

class Ptr : public WPtr {
    inline static void incRefCount(Ob * ob);
    inline static void decRefCount(Ob * ob);
public:
    Ptr() : WPtr(Ob::anil.ob) {incRefCount(ob);}
    Ptr(Ob * _ob) : WPtr(_ob) {incRefCount(ob);}
    Ptr(const Ptr & p) : WPtr(p.ob) {incRefCount(ob);}
    Ptr(const WPtr & p) : WPtr(p.ob) {incRefCount(ob);}
    Ptr(bool b) : WPtr(b ? Ob::at.ob : Ob::anil.ob) {incRefCount(ob);}
    ~Ptr() {decRefCount(ob);}


    Ptr & operator=(const Ptr & p) {return operator=(p.ob);}
    Ptr & operator=(const WPtr & p) {return operator=(p.ob);}
    Ptr & operator=(Ob * _ob) {
        if(_ob != ob) {
            // don't change order
            incRefCount(_ob);
            decRefCount(ob);
            ob = _ob;
        }
        return *this;
    }
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

inline Ptr WPtr::car() const
{
    return ob->car();
}

inline Ptr WPtr::cdr() const
{
    return ob->cdr();
}

inline Ptr WPtr::eval(const Ptr &a) const
{
    return ob->eval(a);
}

inline Ptr WPtr::apply(const Ptr &p, const Ptr &a) const
{
    return ob->apply(p, a);
}

inline Ptr WPtr::unlazy() const
{
    return ob->unlazy();
}

inline Ptr WPtr::assoc(const Ptr &s) const
{
    return ob->assoc(s);
}



inline bool operator==(const Ob * const & ob, const WPtr & p) {return ob == p.ob;}
inline bool operator!=(const Ob * const & ob, const WPtr & p) {return ob != p.ob;}

