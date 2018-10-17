#ifndef DummyClasses_hpp
#define DummyClasses_hpp

#include "Interfaces.h"
#include <stdio.h>
#include <string>


class ADummy : public IClient, public ICollegue, public ISubscriber {
    
    IService* _object;
    IMediator* _mediator;
    std::string hash = std::to_string(rand());
    
public:
    ADummy(IService* object, IMediator* mediator): _object(object), _mediator(mediator) {}
    virtual ~ADummy() {};
    
    void request_action() override;
    void call() override;
    void on_state_changed(ISubject* subject) override;
    
    std::string get_hash();
};

class BDummy : public IService, public ISubject {
    
    IObserver* _observer;
    void notify_all() override;

public:
    
    void action() override;
    
    void change_state();
    void set_observer(IObserver* observer);
};



#endif /* DummyClasses_hpp */
