#ifndef EVENT_H
#define EVENT_H

#include "state.h"

#include <iostream>

template <typename V>
class event
{
public:
  event(int32_t count = 0)
    : _count(count)
  {}

  template <typename S>
  void react(state<S> &v)
  {
    static_cast<V *>(this)->template react<S>(v);
  }
  int32_t _count = 0;
};

class buy_event : public event<buy_event>
{
public:
  buy_event(int32_t count = 0)
    : event(count)
  {}

  template <typename S>
  void react(state<S> &state)
  {
    std::cout << "info: buy_event" << std::endl;
  }
};

class sell_event : public event<sell_event>
{
public:
  sell_event(int32_t count = 0)
    : event(count)
  {}
  template <typename S>
  void react(state<S> &state)
  {
    std::cout << "info: sell_event" << std::endl;
  }
};

#endif
