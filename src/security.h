#pragma once

#include <iostream>
#include <security.h>

template<typename V>
class visitor
{
  public:
  template<typename S>
   void visit(security<S>& v) {
       static_cast<V*>(this)->template visit<S>(v);
   }    
};

class buyer : public visitor<buyer>
{
  public:
    template<typename S>
    void visit(security<S>& security)
    {
      std::cout<< "info: buyer, " << security.name << std::endl;
    }
};

class seller : public visitor<seller>
{
  public:
    template<typename S>
    void visit(security<S>& security)
    {
      std::cout<< "info: buyer, " << security.name << std::endl;
    }
};