#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("---Q5---\n");
	const float big=1e20;
	const float little=-1e20;
	const float pi=3.14;
	float y = (big + little)+pi;
	float z = big + (little + pi);
	if (y==z) printf("This is an example of the associative property.\n");
	else printf("This is a counter-example.. the associative property does not hold!\n");
	return 0;
}