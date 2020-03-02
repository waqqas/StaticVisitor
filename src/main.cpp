
#include "event.h"
#include "fsm/fsm.h"

#include <iostream>

int main(void)
{
  Pico::Fsm::Fsm<state1, state2, state3> fsm;

  buy_event  buy;
  sell_event sell;

  fsm.post(buy);
  fsm.post(sell);

  return 0;
}
