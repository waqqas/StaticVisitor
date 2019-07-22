
#include "operation.h"
#include <iostream>

int main(void)
{

  {
    buyer          buy{10};
    seller         sell{5};
    security_type1 s1;

    s1.accept(buy);
    s1.accept(sell);
    std::cout << "s1: count " << s1.count << std::endl;
  }
  {
    buyer          buy{5};
    seller         sell{10};
    security_type2 s2;
    s2.accept(buy);
    s2.accept(sell);

    std::cout << "s2: count " << s2.count << std::endl;
  }

  return 0;
}
