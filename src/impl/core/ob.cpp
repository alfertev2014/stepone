#include <ptr.h>
#include <impl/core/core.h>
#include <error_exception.h>

namespace stepone {

const Ptr Ptr::anil(new core::Symbol);
const Ptr Ptr::at(new core::Symbol);

}

namespace stepone::core {

Ob::~Ob() {}

Ptr Ob::car() {throw SemanticError("throw car ");}

Ptr Ob::cdr() {throw SemanticError("throw cdr ");}

Ptr Ob::eval(const Ptr &a) {throw SemanticError();}

Ptr Ob::apply(const Ptr &p, const Ptr &a) {
    if(p == Ptr::anil) return this;
    throw SemanticError("apply of not applyable");
}

Ptr Ob::unlazy() {return this;}

Ptr Ob::assoc(const Ptr &s) const {throw SemanticError("throw assoc ");}

} // namespaces
