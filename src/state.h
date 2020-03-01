#ifndef STATE_H
#define STATE_H

#include "fsm/state.h"

#include <iostream>
#include <string>

class base_state : public state<base_state>
{
};

class state1 : base_state
{
public:
  template <typename V>
  void post(event<V> &v)
  {
    v.template react<state1>(*this);
  }
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