#ifndef STATE_H
#define STATE_H

#include <string>

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

  // template <typename V>
  // void transit(event<V> &v)
  // {
  //   static_cast<S *>(this)->template post<V>(v);
  // }
};

class state1 : public state<state1>
{
public:
  template <typename V>
  void post(event<V> &v)
  {
    v.template react<state1>(*this);
  }
};

class state2 : public state<state2>
{
public:
  template <typename V>
  void post(event<V> &v)
  {
    v.template react<state2>(*this);
  }
};

#endif