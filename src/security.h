#pragma once

#include <iostream>
#include <stock.h>

template <typename V> class visitor {
public:
  template <typename S> void visit(security<S> &v) {
    static_cast<V *>(this)->template visit<S>(v);
  }
  int32_t _count = 0;
};

class buyer : public visitor<buyer> {
public:
  template <typename S> void visit(security<S> &security) {
    std::cout << "info: buyer, " << security.name << std::endl;
    security.increment(_count);
  }
};

class seller : public visitor<seller> {
public:
  template <typename S> void visit(security<S> &security) {
    std::cout << "info: buyer, " << security.name << std::endl;
    security.decrement(_count);
  }
};