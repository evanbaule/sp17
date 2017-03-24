#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv){
	printf("---Q4---\n");
	int x=INT_MAX;
	int y=(x | (-1-x));

	printf("%x\n", x);
	printf("%x\n", y);

	if (y==-1) printf("How did you know that?\n");
	else printf("Special value of x!\n");

	return 0;
}