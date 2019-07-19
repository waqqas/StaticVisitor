#pragma once
#include <string>

#include "visitor.h"

template<typename T>
class stock
{
  public:
   virtual void accept(visitor& v)= 0;
};

class security_type1 : public stock<security_type1> {
  public:
    virtual void accept(visitor& v) override
    {
      v.visit(*this);
    }
};


class security_type2 : public stock<security_type2> {
  public:
    virtual void accept(visitor& v) override
    {
      v.visit(*this);
    }
};



