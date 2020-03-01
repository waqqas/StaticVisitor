#pragma once

template <typename E>
class event
{
public:
  template <typename S>
  inline void react(S &v)
  {
    static_cast<E *>(this)->template react<S>(v);
  }
};
