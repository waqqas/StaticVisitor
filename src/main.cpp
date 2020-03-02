
#include "event.h"
#include "fsm/fsm.h"

#include <iostream>

int main(void)
{
  Pico::Fsm::Fsm<state1, state2> fsm;

  buy_event  buy;
  sell_event sell;
  // state1     s1;
  // state2     s2;

  fsm.post(buy);
  fsm.post(sell);
  // fsm.post(sell);

  return 0;
}
