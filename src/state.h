#ifndef STATE_H
#define STATE_H

#include "fsm/fsm.h"

#include <iostream>
#include <string>

class base_state : public Pico::Fsm::State<base_state>
{
};

class state1 : base_state
{
public:
  template <typename E, typename State, typename... States>
  void post(typename Pico::Fsm::Fsm<State, States...> &fsm, E &event)
  {
    event.template react<state1>(fsm, *this);
  }
};

class state2 : base_state
{
public:
  template <typename E, typename State, typename... States>
  void post(typename Pico::Fsm::Fsm<State, States...> &fsm, E &event)
  {
    event.template react<state2>(fsm, *this);
  }
};

class state3 : base_state
{
public:
  template <typename E, typename State, typename... States>
  void post(typename Pico::Fsm::Fsm<State, States...> &fsm, E &event)
  {
    event.template react<state3>(fsm, *this);
  }
};

#endif