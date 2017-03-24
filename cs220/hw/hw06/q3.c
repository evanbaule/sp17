#include <stdio.h>
#include <limits.h>


int main(int argc, char **argv){
	printf("---Q3---\n");
	int x = INT_MAX;
	int y = INT_MAX;
	unsigned int v=x;
  	unsigned int w=y;

	printf("x:\t%d\n", x);
	printf("x:\t%x\n", x);

	printf("y:\t%d\n", y);
	printf("y:\t%x\n", y);

	printf("v:\t%d\n", v);
	printf("v:\t%x\n", v);

	printf("w:\t%d\n", w);
	printf("w:\t%x\n", w);
	printf("-------\n");
	
	int z = x + y;
	unsigned a = v + w;
	printf("z:\t%d\n", z);
	printf("z:\t%x\n", z);

	printf("a:\t%d\n", a);
	printf("a:\t%x\n", a);

	return 0;
}