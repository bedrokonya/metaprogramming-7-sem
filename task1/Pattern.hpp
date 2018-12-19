
#ifndef Handler_hpp
#define Handler_hpp

#include <stdio.h>
#include "DummyClasses.hpp"
#include "Interfaces.h"
#include <unordered_map>
#include <string>
#include <vector>

enum pattern_type {
    PROXY,
    MEDIATOR,
    OBSERVER
};

template <pattern_type TYPE>
class Pattern {
public:
};

template<>
class Pattern<pattern_type::PROXY> : public IService {
    
    BDummy* _real_object;
    
public:
    void action();
};

template<>
class Pattern<pattern_type::MEDIATOR> : public IMediator {
    
    std::unordered_map<std::string, IService*> _pool;

public:
    void addObject(const std::string &hash, IService* object);
    void notify(const std::string &hash);
    void remove_object(const std::string &hash);
};


// Данная реализация Observer'a не может следить за несколькими объектами сразу
// Вообще, это можно было бы обойти, но дедлайн уже почти наступил
template <>
class Pattern<pattern_type::OBSERVER> : public IObserver {
    
    std::vector<ISubscriber*> subscriptions;
    
public:
    void handle(ISubject *subject);
    void subscribe(ISubscriber *subscriber);
};

#endif /* Handler_hpp */
