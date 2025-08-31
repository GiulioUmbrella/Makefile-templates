#include <stdio.h>

#include "foo.hpp"
#include "boo.hpp"

int
main(void)
{   
	printf("%d\n", boo(2));
    printf("%d\n",constant1);
	printf("%d\n", constant2);

	return 0;
}
