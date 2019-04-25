#include <ptr.h>
#include <impl/core/core.h>
#include <error_exception.h>

#include <dbg.h>

namespace stepone {

const Ptr Ptr::anil(new core::Symbol);
const Ptr Ptr::at(new core::Symbol);

}

namespace stepone::core {

Ob::~Ob() {}

Ptr Ob::car() {DBG("throw car "); throw SemanticError();}

Ptr Ob::cdr() {DBG("throw cdr "); throw SemanticError();}

Ptr Ob::eval(const Ptr &a) {throw SemanticError();}

Ptr Ob::apply(const Ptr &p, const Ptr &a) {
    if(p == Ptr::anil) return this;
    DBG("apply of not applyable"); throw SemanticError();
}

Ptr Ob::unlazy() {return this;}

Ptr Ob::assoc(const Ptr &s) const {DBG("throw assoc "); throw SemanticError();}

} // namespaces
