#ifndef EVENT_H
#define EVENT_H

#include "state.h"

#include <iostream>

class buy_event : public Pico::Fsm::Event<buy_event>
{
public:
  template <typename S, typename State, typename... States>
  void react(typename Pico::Fsm::Fsm<State, States...> &fsm, S &state)
  {
    std::cout << "info: buy_event" << std::endl;
    fsm.template transition<state2>();
  }

  // handling buy_event in state1
  template <typename S = state1, typename State, typename... States>
  void react(typename Pico::Fsm::Fsm<State, States...> &fsm, state1 &state)
  {
    std::cout << "info: buy_event, state1" << std::endl;
  }
};

class sell_event : public Pico::Fsm::Event<sell_event>
{
public:
  template <typename S, typename State, typename... States>
  void react(typename Pico::Fsm::Fsm<State, States...> &fsm, S &state)
  {
    std::cout << "info: sell_event" << std::endl;
  }
};

#endif
