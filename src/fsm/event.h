#pragma once

template <typename V>
class event
{
public:
  template <typename S>
  inline void react(S &v)
  {
    static_cast<V *>(this)->template react<S>(v);
  }
};
