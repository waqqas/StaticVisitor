
#include "event.h"

#include <iostream>

int main(void)
{

  buy_event  buy;
  sell_event sell;
  state1     s1;
  state2     s2;

  s1.post(buy);
  s1.post(sell);

  return 0;
}
