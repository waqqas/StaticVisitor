#pragma once

#include <iostream>
#include <security.h>

template <typename V>
class operation
{
public:
  operation(int32_t count = 0): _count(count){}

  template <typename S>
  void visit(security<S> &v)
  {
    static_cast<V *>(this)->template visit<S>(v);
  }
  int32_t _count = 0;
};

class buyer : public operation<buyer>
{
public:
  buyer(int32_t count = 0): operation(count) {} 
  template <typename S>
  void visit(security<S> &security)
  {
    std::cout << "info: buyer, " << security.name << std::endl;
    security.increment(_count);
  }
};

class seller : public operation<seller>
{
public:
  seller(int32_t count = 0): operation(count) {}
  template <typename S>
  void visit(security<S> &security)
  {
    std::cout << "info: seller, " << security.name << std::endl;
    security.decrement(_count);
  }
};