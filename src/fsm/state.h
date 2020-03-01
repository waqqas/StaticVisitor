#pragma once

#include "fsm/event.h"

template <typename T>
class event;

template <typename S>
class state
{
public:
  template <typename V>
  inline void post(event<V> &v)
  {
    static_cast<S *>(this)->template post<V>(v);
  }
};
