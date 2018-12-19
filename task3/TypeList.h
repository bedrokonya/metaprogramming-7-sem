#ifndef Typelist_h
#define Typelist_h

struct NullType {};

template <typename ...Args>
struct TypeList {
    using head = NullType;
    using tail = NullType;
};

typedef TypeList<> EmptyList;

template <typename H, typename ...T>
struct TypeList<H, T...> {
    using head = H;
    using tail = TypeList<T...>;
};


template <typename TList>
struct SizeOf;

template <>
struct SizeOf<EmptyList> {
    static const int value = 0;
};

template <typename H, typename ...T>
struct SizeOf<TypeList<H, T...>> {
    static const int value = sizeof(H) + SizeOf<TypeList<T...>>::value;
};

#endif

