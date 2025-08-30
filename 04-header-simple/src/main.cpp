#include <stdio.h>

#include <boo.h>
#include <foo.h>

int
main(void)
{   
	printf("%d\n", boo(2));
    printf("%d\n", foo(2));
	printf("%d\n",ValueFoo);
	printf("%d\n",ValueBoo);

	return 0;
}
