#include <stdio.h>
#include <time.h>
//Count up Loops
void forLoop(unsigned int n) {
	unsigned int i;
	for(i = 0; i < n; i++)
		;
}

void whileLoop(unsigned int n){
  unsigned int i = 0;
  while(i < n)
    i++;
}

void doWhile(unsigned int n){
  unsigned int i = 0;
  do{
    i++;
  } while(i < n);
}

//Count down Loops
void forDown(unsigned int n){
  unsigned int i;
  for(i = n; i > 0; i--){
    ;
  }

}

void whileDown(unsigned int n){
  unsigned int i = n;
  while(i > 0){
    i--;
  }
  
}

void doDown(unsigned int n){
  unsigned int i = n;
  do{
    i--;
  } while(i > 0);
  
}

/* Add other looping functions here */

float timeFunction(void (*function)(unsigned int n), int n) {
	clock_t tic = clock();
   function(n);
   clock_t toc = clock();
   return (float)(toc - tic) / CLOCKS_PER_SEC;
}

int main()
{

	printf("Function: forLoop takes : %f seconds for 1,000,000,000 iterations\n",
    	    timeFunction(forLoop,1000000000));
  printf("Function: whileLoop takes : %f seconds for 1,000,000,000 iterations\n",
          timeFunction(whileLoop,1000000000));
  printf("Function: doWhile takes : %f seconds for 1,000,000,000 iterations\n",
          timeFunction(doWhile,1000000000));

  printf("BREAK\n");

  printf("Function: forDown takes : %f seconds for 1,000,000,000 iterations\n",
          timeFunction(forDown,1000000000));
  printf("Function: whileDown takes : %f seconds for 1,000,000,000 iterations\n",
          timeFunction(whileDown,1000000000));
  printf("Function: doDown takes : %f seconds for 1,000,000,000 iterations\n",
          timeFunction(doDown,1000000000));
    /* Insert code to time the other loops here */

    return 0;
}
