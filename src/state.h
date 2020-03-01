#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include "fsm/state.h"

class base_state : public state<base_state>
{
};

// class state2;

class state1 : base_state
{
public:
  template <typename V>
  void post(event<V> &v)
  {
    v.template react<state1>(*this);
  }

  // template <>
  // void transition<state2>()
  // {
  //   std::cout << "state1 => state2" << std::endl;
  // }
};

class state2 : base_state
{
public:
  template <typename V>
  void post(event<V> &v)
  {
    v.template react<state2>(*this);
  }
};

#endif