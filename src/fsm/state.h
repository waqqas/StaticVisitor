#pragma once

#include "fsm/event.h"

template <typename E>
class event;

template <typename S>
class state
{
public:
  template <typename E>
  inline void post(event<E> &v)
  {
    static_cast<S *>(this)->template post<E>(v);
  }
};
