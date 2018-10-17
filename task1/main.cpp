
#include <iostream>
#include <array>
#include <string>
#include "Pattern.hpp"
#include "DummyClasses.hpp"

int main() {

    Pattern<pattern_type::PROXY> proxy;
    Pattern<pattern_type::MEDIATOR> mediator;
    Pattern<pattern_type::OBSERVER> observer;

    ADummy a(&proxy, &mediator);
    BDummy b;
    
    // PROXY TEST
    a.request_action();
    
    std::cout << std::endl;
    
    // MEDIATOR TEST
    mediator.addObject(a.get_hash(), new BDummy());
    a.call();
    
    std::cout << std::endl;
    
    // OBSERVER TEST
    b.set_observer(&observer);
    observer.subscribe(&a);
    b.change_state();
    
    return 0;
}
