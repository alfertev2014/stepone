#include <init/initevaluator.h>

#include <impl/objects/basefunc_obs.h>
#include <impl/objects/basenumfunc_obs.h>
#include <impl/objects/basemacro_obs.h>
#include <impl/objects/typepredicates_obs.h>
#include <impl/objects/bytearray_obs.h>
#include <impl/objects/vector_obs.h>

#include <impl/ptr_impl.h>

namespace stepone::init {

using namespace objects;

Ptr BaseEvaluator::createContext()
{
    Ptr ctx;
    ctx = BaseNumFunc::inst().populateContext(ctx);
    ctx = VectorFunctions::inst().populateContext(ctx);
    ctx = ByteArrayFunctions::inst().populateContext(ctx);
    ctx = BaseTypePredicates::inst().populateContext(ctx);
    ctx = BaseMacroses::inst().populateContext(ctx);

    return ctx;
}

} // namespaces
