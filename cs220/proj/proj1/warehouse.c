#include "slots.h"
#include <stdio.h>

/*
Evan M. Baule
Project 1
CS 220: Comp Systems and Architecture II
*/

#define ARRLEN 100
#define MAX 2147483647

int lowestFreq(); 
int frequency[ARRLEN]; //Frequency table to track which widgets come up the least/most.

/*
main() Process
	1. Sets each value in the frequency array to 0
	2. Declares index/working values that are used within the loop
	3. Checks the input for next order
	4. If the bin is not already on the table, we check each 4 bins that are currently available
	and remove the one with the least chance of coming up in the future.
	5. We then replace the bin with the one we need, and grab a widget.
*/
int main(int argc, char ** argv) {

	/*Initialize table to all zero*/
	int ze; //ITERATOR
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
				int bindex; //ITERATOR
				int lowestBin = 0; //Index of the bin we will remove, if we dont change this we will remove the first bin.
				for(bindex = 0; bindex < 4; bindex++){
					if(frequency[bindex] < frequency[lowestBin]){
						lowestBin = bindex;
					}
				}
				getBin(bin, lowestBin); //Replaces the lowest freq bin with the one we need.
			}
		}
		getWidget(bin); //Finally pulls the widget out of the necessary bin.
	}
	printEarnings();
	return 0;

}

/*
Function returning an integer representing the index in the frequency
array which holds the lowest integer value.

This is then used to determine which bin to remove from the workbench.
*/
int lowestFreq(){
	int retVal;
	int lowestVal = MAX; //MAX is #defined as the largest value an integer can hold. Avoiding including a library to do this for 1 value.
	int i; //ITERATOR
	for(i = 0; i < ARRLEN; i++){
		if(frequency[i] < lowestVal && frequency[i] != 0){
			lowestVal = frequency[i];
			retVal = i;		}
	}
	return retVal;
}
