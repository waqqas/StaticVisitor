
#include <iostream>
#include "stock.h"
#include "security.h"

int main(void)
{
	security_type1 s1;
	security_type2 s2;
	// security<security_type1> s11;

	buyer b;
	seller s;
	s1.accept(b);
	s2.accept(b);

	s1.accept(s);
	s2.accept(s);


	// s11.accept(b);

	return 0;
}

