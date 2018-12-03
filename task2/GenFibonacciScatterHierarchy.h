#ifndef GenFibonacciScatterHierarchy_h
#define GenFibonacciScatterHierarchy_h

#include "FibonacciNumber.h"
#include "GenLinearHierarchy.h"
#include "Typelist.h"

/*
 ** Объявление вспомогательного составного элемента всей иерархии
 */
template
<
    unsigned int branch_index,
    unsigned int current_size,
    unsigned int fib_num_size,
    typename GatheredTList,
    typename RemainTList,
    template <typename T, class Parent> class Unit,
    unsigned int absolute_index
>
class Component;


/*
 ** Специализация случая, когда в тайплисте RemainTList больше нет элементов, которые можно добавить в GatheredTList,
 ** при этом текущий размер ветки не равен branch_index-ому числу Фибоначчи.
 ** Наследуемся от GenLinearHierarchy, который сгенерирует линейную иерархию из элементов в GatheredTail
 */
template
<
    unsigned int branch_index,
    unsigned int current_size,
    unsigned int fib_num_size,
    typename ...GatheredTail,
    template <typename T, class Parent> class Unit,
    unsigned int absolute_index
>
class Component<branch_index, current_size, fib_num_size, TypeList<GatheredTail...>, EmptyList, Unit, absolute_index> :
    public GenLinearHierarchy<TypeList<GatheredTail...>, Unit> {};

/*
 ** Специализация случая, когда в тайплисте RemainTList больше нет элементов, которые можно добавить в GatheredTList,
 ** при этом текущий размер ветки равен branch_index-ому числу Фибоначчи.
 ** Наследуемся от GenLinearHierarchy, который сгенерирует линейную иерархию из элементов в GatheredTail
 */
template
<
    unsigned int branch_index,
    unsigned int fib_num_size,
    typename ...GahtheredTail,
    template <typename T, class Parent> class Unit,
    unsigned int absolute_index
>
class Component<branch_index, fib_num_size, fib_num_size, TypeList<GahtheredTail...>, EmptyList, Unit, absolute_index> :
    public GenLinearHierarchy<TypeList<GahtheredTail...>, Unit> {} ;

/*
 ** Специализация случая, когда в тайплисте RemainTList еще есть элементы,
 ** из которых можно наращивать текущую ветку  (которые можно сложить в GatheredTList)
 */
template
<
    unsigned int branch_index,
    unsigned int current_size,
    unsigned int fib_num_size,
    typename ...GatheredTail,
    typename Head,
    typename ...RemainTail,
    template <typename T, class Parent> class Unit,
    unsigned int absolute_index
>
class Component<branch_index, current_size, fib_num_size, TypeList<GatheredTail...>, TypeList<Head, RemainTail...>, Unit, absolute_index> :
    public Component<branch_index, current_size + 1, fib_num_size, TypeList<Head, GatheredTail...>, TypeList<RemainTail...>, Unit, absolute_index + 1> {};


/*
 ** Текущая ветка достигла нужного размера, равного branch_index-ому номеру Фибоначчи,
 ** при этом в RemainTList есть еще как минимум один элемент, из которого можно будет начать составлять следующую по номеру ветку.
 ** Наследуемся от GenLinearHierarchy, который сгенерирует линейную иерархию из элементов в GatheredTail
 */
template
<
    unsigned int branch_index,
    unsigned int fib_num_size,
    typename ...GatheredTail,
    typename Head,
    typename ...RemainTail,
    template <typename T, class Parent> class Unit,
    unsigned int absolute_index
>
class Component<branch_index, fib_num_size, fib_num_size, TypeList<GatheredTail...>, TypeList<Head, RemainTail...>, Unit, absolute_index> :
    public GenLinearHierarchy<TypeList<GatheredTail...>, Unit>,
    public Component<branch_index + 1, 0, FibonacciNumber<branch_index + 1>::value, EmptyList, TypeList<Head, RemainTail...>, Unit, absolute_index + 1> {};


/*
 ** Объявление GenFibonacciScatterHierarchy
 */
template
<
    typename Tlist,
    template <typename T, class Parent> class Unit
>
class GenFibonacciScatterHierarchy :
    public Component<0, 0, FibonacciNumber<0>::value, EmptyList, Tlist, Unit, 0> {};

#endif
