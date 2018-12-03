#ifndef Holder_h
#define Holder_h

template <typename T, class Parent> struct Holder;

template <typename T, class Parent>
struct Holder : public Parent {
    T* value;
};

#endif 
