#pragma once

#include "fsm/event.h"

namespace Pico {
namespace Fsm {
template <typename S>
class State
{
public:
  template <typename E>
  inline void post(E &event)
  {
    static_cast<S *>(this)->template post<E>(event);
  }
};

}  // namespace Fsm
}  // namespace Pico
