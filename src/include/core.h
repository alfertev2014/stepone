#pragma once

#include "type_flags.h"

#include "dbg.h"

class Ob;
class Ptr;

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
    void acqure();
    void release();
    void assing(Ob * _ob);
public:
    static const Ptr anil;
    static const Ptr at;

    Ptr(Ob * _ob) : WPtr(_ob) {acqure();}
    Ptr(const Ptr & p) : WPtr(p.ob) {acqure();}
    Ptr(const WPtr & p) : WPtr(p.ob) {acqure();}
    Ptr(bool b) : WPtr(b ? at.ob : anil.ob) {acqure();}
    ~Ptr() {release();}

    Ptr & operator=(const Ptr & p) {return operator=(p.ob);}
    Ptr & operator=(const WPtr & p) {return operator=(p.ob);}
    Ptr & operator=(Ob * _ob) {
        assing(_ob);
        return *this;
    }
};
inline bool operator==(const Ob * const & ob, const WPtr & p) {return ob == p.ob;}
inline bool operator!=(const Ob * const & ob, const WPtr & p) {return ob != p.ob;}


class SemanticError {};

class TypeInfoBase;

class Ob {
    friend class Ptr;
    int refcount;

    void incRefCount() {
       refcount++;
    }

    void decRefCount() {
        refcount--;
        if(refcount == 0)
            delete this;
    }
protected:
    TypeFlags typeFlags;
public:
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


inline void Ptr::acqure() { ob->incRefCount(); }

inline void Ptr::release() { ob->decRefCount(); }

inline void Ptr::assing(Ob *_ob)
{
    if(_ob != ob) {
        // don't change the order
        _ob->incRefCount();
        ob->decRefCount();
        ob = _ob;
    }
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

