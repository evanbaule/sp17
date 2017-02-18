#include "slots.h"
#include <stdio.h>


#define ARRLEN 100
#define MAX 2147483647

int lowestFreq();
int frequency[ARRLEN];

/*
main() Process
	1. Sets each value in the frequency array to 0
	2. Declares index/working values that are used within the loop
	3. 
*/
int main(int argc, char ** argv) {

	/*Initialize table to all zero*/
	int ze;
	for(ze = 0; ze < ARRLEN; ze++){
		frequency[ze] = 0;
	}

	int bin;
	int idx = 0;
	initSlots();
	while(1==scanf("%d",&bin)) {
		frequency[bin]++;
		if (-1==findSlot(bin)) {
			if(idx < 3){idx++; getBin(bin, idx);}
			else{
				/*
				Finds the lowest bin on the table, 
				which is the one that will be removed.
				*/
				int bindex; //Iterator
				int lowestBin = 0; //Index of the bin we will remove, if we dont change this we will remove the first bin.
				for(bindex = 0; bindex < 4; bindex++){
					if(frequency[bindex] < frequency[lowestBin]){
						lowestBin = bindex;
					}
				}
				getBin(bin, lowestBin); //Replaces the lowest freq bin with the one we need.
			}
		}
		getWidget(bin);
	}
	printEarnings();
	return 0;

}

int lowestFreq(){
	int i;
	int low = MAX;
	int ret;
	for(i = 0; i < ARRLEN; i++){
		if(frequency[i] < low && frequency[i] != 0){
			low = frequency[i];
			ret = i;
		}
	}
	return ret;
}
