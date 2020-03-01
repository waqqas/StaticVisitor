#ifndef EVENT_H
#define EVENT_H

#include "fsm/event.h"
#include "state.h"
#include <iostream>

class buy_event : public event<buy_event>
{
public:
  buy_event(int32_t count = 0)
  {}

  template <typename S>
  void react(S &state)
  {
    std::cout << "info: buy_event, other state" << std::endl;
  }

  template <>
  void react(state1 &state)
  {
    std::cout << "info: buy_event, state1" << std::endl;
    // state.transition(state);
  }
};

class sell_event : public event<sell_event>
{
public:
  sell_event(int32_t count = 0)
  {}
  template <typename S>
  void react(S &state)
  {
    std::cout << "info: sell_event" << std::endl;
  }
};

#endif
