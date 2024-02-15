#ifndef MMO_PTRN_OBSERVER_H
#define MMO_PTRN_OBSERVER_H

template <class T>
class Observer {
public:
    virtual void update(T) = 0;
};

#endif