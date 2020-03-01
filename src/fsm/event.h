#pragma once

namespace Pico {
namespace Fsm {
template <typename E>
class Event
{
public:
  template <typename S>
  inline void react(S &state)
  {
    static_cast<E *>(this)->template react<S>(state);
  }
};
}  // namespace Fsm
}  // namespace Pico
