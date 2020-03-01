#ifndef EVENT_H
#define EVENT_H

#include "fsm/event.h"
#include "state.h"

#include <iostream>

class buy_event : public event<buy_event>
{
public:
  template <typename S>
  void react(S &state)
  {
    std::cout << "info: buy_event, other state" << std::endl;
  }

  // handling buy_event in state1
  template <>
  void react(state1 &state)
  {
    std::cout << "info: buy_event, state1" << std::endl;
  }
};

class sell_event : public event<sell_event>
{
public:
  template <typename S>
  void react(S &state)
  {
    std::cout << "info: sell_event" << std::endl;
  }
};

#endif
