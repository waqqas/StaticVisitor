#ifndef EVENT_H
#define EVENT_H

#include "state.h"

#include <iostream>

class BuyEvent : public Pico::Fsm::Event<BuyEvent>
{
public:
  template <typename S, typename... States>
  void react(typename Pico::Fsm::Fsm<States...> &fsm, S &state)
  {
    std::cout << "info: BuyEvent" << std::endl;
  }

  // handling BuyEvent in State1
  template <typename S = State1, typename... States>
  void react(typename Pico::Fsm::Fsm<States...> &fsm, State1 &state)
  {
    std::cout << "info: BuyEvent, State1" << std::endl;
    fsm.template transition<State2>();
  }
};

class SellEvent : public Pico::Fsm::Event<SellEvent>
{
public:
  template <typename S, typename... States>
  void react(typename Pico::Fsm::Fsm<States...> &fsm, S &state)
  {
    std::cout << "info: SellEvent" << std::endl;
  }
};

#endif
