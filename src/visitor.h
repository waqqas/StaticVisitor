#pragma once

#include <iostream>

class security_type1;
class security_type2;

class visitor
{
  public:
    virtual void visit(security_type1& el) = 0;
    virtual void visit(security_type2& el) = 0;
};

class visitor_concrete : public visitor
{
  public:
    virtual void visit(security_type1& el) override
    {
      std::cout << "stock: 1"  << std::endl;
    };
    virtual void visit(security_type2& el) override
    {
      std::cout << "stock: 2" << std::endl;
    };
};

