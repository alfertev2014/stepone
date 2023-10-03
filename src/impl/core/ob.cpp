#include <ptr.h>
#include <ob.h>
#include <error_exception.h>

#include <type_traits>

namespace stepone {

const Ptr Ptr::anil() {
    static const Ptr p = Ptr::of<core::Symbol>();
    return p;
}

const Ptr Ptr::at() {
    static const Ptr p = Ptr::of<core::Symbol>();
    return p;
}

}

namespace stepone {

Ptr Ob::car() {
    return cast<core::Pair>().car();
}

Ptr Ob::cdr() {
    return cast<core::Pair>().cdr();
}

} // namespaces
