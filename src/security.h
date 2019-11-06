#pragma once

#include <string>

template <typename T>
class operation;

template <typename S>
class security
{
public:
  security(std::string name)
    : name(name)
  {}

  template <typename V>
  void accept(operation<V> &v)
  {
    static_cast<S *>(this)->template accept<V>(v);
  }

  void increment(int32_t inc)
  {
    count += inc;
  }

  void decrement(int32_t dec)
  {
    count -= dec;
  }

  std::string name  = "none";
  int32_t     count = 0;
};

class security_type1 : public security<security_type1>
{
public:
  security_type1()
    : security("type1")
  {}
  template <typename V>
  void accept(operation<V> &v)
  {
    v.template visit<security_type1>(*this);
  }
};

class security_type2 : public security<security_type2>
{
public:
  security_type2()
    : security("type2")
  {}
  template <typename V>
  void accept(operation<V> &v)
  {
    v.template visit<security_type2>(*this);
  }
};
