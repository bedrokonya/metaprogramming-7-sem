#ifndef Interfaces_h
#define Interfaces_h
#include <string>

// используется для работы с PROXY
class IService {
public:
    virtual ~IService() {};
    
    virtual void action() = 0;
};

// используется для работы с PROXY
class IClient {
public:
    virtual ~IClient() {};
    
    virtual void request_action() = 0;
    
};

// используется для работы с MEDIATOR
class IMediator {
public:
    virtual ~IMediator() {};
    
    virtual void addObject(const std::string &hash, IService* object) = 0;
    virtual void notify(const std::string &hash) = 0;
    virtual void remove_object(const std::string &hash) = 0;
};

// используется для работы с MEDIATOR
class ICollegue {
public:
    virtual ~ICollegue() {};
    
    virtual void call() = 0;
};

// используется для работы с OBSERVER
class ISubject {
public:
    ~ISubject() {};
    
private:
    
    virtual void notify_all() = 0;
};

// используется для работы с OBSERVER
class ISubscriber {
public:
    virtual ~ISubscriber() {};
    virtual void on_state_changed(ISubject* subject) = 0;
};

// используется для работы с OBSERVER
class IObserver {
public:
    virtual void handle(ISubject* subject) = 0;
    virtual void subscribe(ISubscriber* subscriber) = 0;
    
};

#endif /* Interfaces_h */
