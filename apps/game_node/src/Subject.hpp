#ifndef MMO_PTRN_SUBJECT_H
#define MMO_PTRN_SUBJECT_H

#include "Observer.hpp"
#include <vector>
#include <functional>


template <class Type>
class Subject {
public:
   virtual ~Subject() = 0;
   void registerObserver(Observer<Type> &o) 
   {
       mObservers.push_back(o);
   }

   void notifyObservers(Type value) 
   {
      for (const auto& o: mObservers)
      {
            o.get().update(value);
      }
   }

private:
   std::vector<std::reference_wrapper<Observer<Type>>> mObservers;
};

template <class Type>
Subject<Type>::~Subject() {}

#endif