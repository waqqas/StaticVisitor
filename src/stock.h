#pragma once
#include <string>

#include "visitor.h"

template<typename T>
class stock
{
  public:
   void accept(visitor& v) {
       static_cast<T*>(this)->accept(v);
   }   
};

class security_type1 : public stock<security_type1> {
  public:
    void accept(visitor& v)
    {
      v.visit(*this);
    }
};


class security_type2 : public stock<security_type2> {
  public:
    void accept(visitor& v)
    {
      v.visit(*this);
    }
};



