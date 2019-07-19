
#include <iostream>
#include "stock.h"

int main(void)
{
	security_type1 s1;
	security_type2 s2;
	visitor_concrete v1;
	s1.accept(v1);
	s2.accept(v1);

	return 0;
}

