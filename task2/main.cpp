
#include <iostream>
#include "Typelist.h"
#include "FibonacciNumber.h"
#include "Holder.h"
#include "GenLinearHierarchy.h"
#include "GenFibonacciScatterHierarchy.h"

#include <vector>
#include <list>

/**
 
 Второе задание:
    Есть typelist. Необходимо сгенерировать следующую иерархию.
    Корневой класс должен наследовать одновременно несколько классов (веток).
    Классы-ветки нумеруются начиная с нуля.
    Каждый класс-ветка должен, в свою очередь последовательно наследовать (линейно)
    n_i классов, где i - номер ветки, n_i - итое число фиббоначи.
    Порядок "выбора" типов из typelist следующий: нулевой класс-ветка,
    его "дети', следующий класс-ветка, все его "дети" и т.д.
 
 **/

int main(int argc, const char * argv[]) {

    TypeList<char, int, long> list;
    FibonacciNumber<7> fibNum7;
    std::cout << fibNum7.value << std::endl;
    
    GenFibonacciScatterHierarchy<TypeList<int, double, float, char, bool, long, short>, Holder> hierarchy;
   
    GenFibonacciScatterHierarchy<EmptyList, Holder> empty_hierarchy;
    
    return 0;
}
