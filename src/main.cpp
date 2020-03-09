
#include "event.h"
#include "fsm/fsm.h"

#include <iostream>

int main(void)
{
  Pico::Fsm::Fsm<State1, State2, State3> fsm;

  BuyEvent  buy;
  SellEvent sell;

  fsm.post(buy);
  fsm.post(sell);

  return 0;
}
