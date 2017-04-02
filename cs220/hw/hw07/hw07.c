#include <stdio.h>

int main(){

	int x = 16843009;

	if(x==htonl(x)){
		printf("palindrome\n");
	}
	else {
		printf("not palindrome");
	}
	return 0;
}
