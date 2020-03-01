
#include "event.h"

#include <iostream>

int main(void)
{

  {
    buy_event   buy(10);
    sell_event  sell(5);
    state1 s1;
    state2 s2;

    s1.post(buy);
    s1.post(sell);
  }
  {
    buy_event   buy(5);
    sell_event  sell(10);
    state2 s2;
    s2.post(buy);
    s2.post(sell);
  }

  return 0;
}
