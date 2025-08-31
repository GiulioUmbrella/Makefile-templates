#include <stdio.h>

#include "foo.h"
#include "boo.h"
#include "zoo.h"

int
main(void)
{   
	printf("%d\n", boo(1));
    printf("%d\n", foo(2));
	printf("%d\n", zoo(3));

	return 0;
}
