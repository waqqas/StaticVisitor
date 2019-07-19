#pragma once

#include <string>

template<typename T>
class visitor;

template<typename S>
class security
{
  public:
  template<typename V>
   void accept(visitor<V>& v) {
       static_cast<S*>(this)->template accept<S>(v);
   }

   std::string name = "none";

};

class security_type1 : public security<security_type1> {
  public:
    security_type1(): security{"type1"} {}
    template<typename V>
    void accept(visitor<V>& v)
    {
      v.template visit<security_type1>(*this);
    }
};


class security_type2 : public security<security_type2> {
  public:
  security_type2(): security{"type2"} {}
  template<typename V>
    void accept(visitor<V>& v)
    {
      v.template visit<security_type2>(*this);
    }
};



