#pragma once

#include <ptr.h>
#include "type_flags.h"
#include "error_exception.h"

namespace stepone::core {

class Ob {
    friend class ::stepone::Ptr;
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

    template <class T>
    T * as() {
        return dynamic_cast<T*>(this);
    }

    template <class T>
    bool is() const;

    template <class T>
    T * cast() {
        if(is<T>())
            return as<T>();
        throw SemanticError("error cast");
    }

};

template <class T>
inline bool Ob::is() const {
    return dynamic_cast<const T*>(this) != nullptr;
}

} // namespaces
