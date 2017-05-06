#include <impl/core/value.h>

template<>
ValueBase *Ob::as<ValueBase>() {return typeFlags.constType == TypeFlags::ValueBase ? dynamic_cast<ValueBase*>(this) : 0;}

ValueBase::~ValueBase() {}
