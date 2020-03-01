#ifndef STATE_H
#define STATE_H

#include "fsm/state.h"

#include <iostream>
#include <string>

class base_state : public Pico::Fsm::State<base_state>
{
};

class state1 : base_state
{
public:
  template <typename E>
  void post(E &event)
  {
    event.template react<state1>(*this);
  }
};

class state2 : base_state
{
public:
  template <typename E>
  void post(E &event)
  {
    event.template react<state2>(*this);
  }
};

#endif