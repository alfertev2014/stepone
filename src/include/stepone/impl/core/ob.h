#pragma once

#include <ptr.h>
#include "type_flags.h"

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

    virtual const Ptr getTypeInfo() const = 0;

    template <class T>
    T * as();
    template <class T>
    bool is() const;
    template <class T>
    T * cast();
};


