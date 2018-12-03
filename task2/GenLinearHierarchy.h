
#ifndef GenLinearHierarchy_h
#define GenLinearHierarchy_h

#include "Typelist.h"

template
<
    typename TList,
    template <typename T, typename Parent> class Unit
>
class GenLinearHierarchy;

template
<
    typename Head,
    typename ...Tail,
    template <typename T, typename Parent> class Unit
>
class GenLinearHierarchy<TypeList<Head, Tail...>, Unit> :
    public Unit<Head, GenLinearHierarchy<TypeList<Tail...>, Unit>> {};

template
<
    template <typename T, typename Parent> class Unit
>
class GenLinearHierarchy<EmptyList, Unit> : public Unit<NullType, NullType> {};

#endif
