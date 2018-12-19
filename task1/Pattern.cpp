
#include "Pattern.hpp"
#include <iostream>

// PROXY
void Pattern<pattern_type::PROXY>::action() {
    
    if (this->_real_object == nullptr) {
        _real_object = new BDummy();
    }
    std::cout << "PROXY is passing on request to object B: " << _real_object << std::endl;
    _real_object->action();
}

// MEDIATOR
void Pattern<pattern_type::MEDIATOR>::addObject(const std::string &hash, IService* object) {
    std::cout << "MEDIATOR added object B: " << object << " for hash: " << hash << std::endl;
    _pool[hash] = object;
}

void Pattern<pattern_type::MEDIATOR>::notify(const std::string &hash) {
    
    std::cout << "MEDIATOR is trying to find approriate object B for object A" << std::endl;
    IService* object = _pool[hash];
    
    if (object == nullptr) {
        std::cout << "There is no approriate BDummy object for hash" << hash << std::endl;
    } else {
        std::cout << "object B: " << object << " has been found for hash:" << hash << std::endl;
        object->action();
    }
}

void Pattern<pattern_type::MEDIATOR>::remove_object(const std::string &hash) {
    _pool.erase(hash);
}

// OBSERVER
void Pattern<pattern_type::OBSERVER>::handle(ISubject* subject) {
    std::cout << "OBSERVER is making all subscribers to react on changes of object B: " << subject << std::endl;
    for (auto s : subscriptions) {
        s->on_state_changed(subject);
    }
}

void Pattern<pattern_type::OBSERVER>::subscribe(ISubscriber *subscriber) {
    std::cout << "OBSERVER has subscribed object A: " << subscriber << std::endl;
    subscriptions.push_back(subscriber);
}


