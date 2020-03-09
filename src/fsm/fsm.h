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
class State
{
};

class StateBase : public Pico::Fsm::State<StateBase>
{
};

template <typename... States>
class Fsm
{
public:
  Fsm()
  {
    current = (void *)&std::get<0>(states);  // first state is the initial state
  }

  template <typename E>
  inline void post(E &event)
  {
    // current->template post<E>(*this, event);
  }

  template <typename S2>
  void transition()
  {
    constexpr int index = 1;
    current             = (void *)&std::get<1>(states);
  }

private:
  using state_list = std::tuple<States...>;
  // using FirstState = typename std::tuple_element<0, state_list>::type;

  state_list states;
  void *     current;
};

}  // namespace Fsm
}  // namespace Pico