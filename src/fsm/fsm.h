#pragma once

#include <memory>
#include <tuple>

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

template <typename S>
class State;

template <typename State, typename... States>
class Fsm
{
public:
  Fsm()
    : current(std::get<0>(states))  // first state is the initial state
  {}

  template <typename E>
  inline void post(E &event)
  {
    current.template post<E>(*this, event);
  }

private:
  using state_list = std::tuple<State, States...>;

  state_list states;
  State &    current;
};

template <typename S>
class State
{
};

}  // namespace Fsm
}  // namespace Pico