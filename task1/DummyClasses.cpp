#include "DummyClasses.hpp"
#include <iostream>

void BDummy::action() {
    std::cout << "object B: " << this << " is making action here" << std::endl;
}

void BDummy::set_observer(IObserver *observer) {
    _observer = observer;
    std::cout << "OBSERVER has been set on object B: " << this << std::endl;
}

void BDummy::change_state() {
    notify_all();
}

void BDummy::notify_all() {
    _observer->handle(this);
}

void ADummy::request_action() {
    std::cout << "object A: "<< this << "is requesting an action" << std::endl;
    _object->action();
}

std::string ADummy::get_hash() {
    return hash;
}
void ADummy::call() {
    std::cout << "object A: " << this << " is calling for approriate object B through MEDIATOR" << std::endl;
    _mediator->notify(hash);
}

void ADummy::on_state_changed(ISubject* subject) {
    std::cout << "object A: " << this << " is reacting on changes of object B:" << subject << std::endl;
}
