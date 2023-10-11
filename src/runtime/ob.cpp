#include <ptr.h>
#include <ob.h>
#include <error_exception.h>

#include <type_traits>

namespace stepone {

const Ptr Ptr::anil() {
    static const Ptr p = Ptr::of<types::Symbol>();
    return p;
}

const Ptr Ptr::at() {
    static const Ptr p = Ptr::of<types::Symbol>();
    return p;
}

}

namespace stepone {

Ptr Ob::car() const {
    return cast<types::Pair>().car;
}

Ptr Ob::cdr() const {
    return cast<types::Pair>().cdr;
}

} // namespaces
