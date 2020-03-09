#ifndef STATE_H
#define STATE_H

#include "fsm/fsm.h"

#include <iostream>
#include <string>

class State1 : Pico::Fsm::StateBase
{
public:
  template <typename E, typename... States>
  void post(typename Pico::Fsm::Fsm<States...> &fsm, E &event)
  {
    event.template react<State1>(fsm, *this);
  }
};

class State2 : Pico::Fsm::StateBase
{
public:
  template <typename E, typename... States>
  void post(typename Pico::Fsm::Fsm<States...> &fsm, E &event)
  {
    event.template react<State2>(fsm, *this);
  }
};

class State3 : Pico::Fsm::StateBase
{
public:
  template <typename E, typename... States>
  void post(typename Pico::Fsm::Fsm<States...> &fsm, E &event)
  {
    event.template react<State3>(fsm, *this);
  }
};

#endif