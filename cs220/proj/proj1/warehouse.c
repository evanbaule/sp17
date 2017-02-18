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

	/*
	The following loop initializes all values of freq[] to 0
	*/
	int ze;
	for(ze = 0; ze < ARRLEN; ze++){
		frequency[ze] = 0;
	}

	int bin;
	int lowest;
	int idx = 0;
	initSlots();
	while(1==scanf("%d",&bin)) {
		frequency[bin]++;
		if (-1==findSlot(bin)) {
			getBin(bin, idx);
			if(idx < (NUMSLOTS - 1)){idx++;}
			else{
				int bindex;
				int lowestBin = 0;
				for(bindex = 0; bindex < 4; bindex++){
					if(frequency[bindex] < frequency[lowestBin]){
						lowestBin = bindex;
					}
				}
				getBin(bin, lowestBin);
			}
		}
		getWidget(bin);
	}
	printEarnings();
	return 0;

	/*
	while(1==scanf("%d",&bin)) {
		frequency[bin]++;
		if (findSlot(bin) == (-1)) {
			getBin(bin,idx);
			if(idx < (NUMSLOTS-1)){
				idx++;
			} else{
				lowest = lowestFreq();
				int j;
				for(j = 0; j < NUMSLOTS; j++){
					if(findSlot(lowest) != -1){
						getBin(bin, j);
					}
					else{
						lowest = lowest-1;
						lowestFreq(lowest);
					}
				}
			}
		}
		frequency[bin]++;
		if(findSlot(bin)== -1){
			if(idx < (NUMSLOTS-1)){getBin(bin, idx); idx++;} 
			else{
				lowest = lowestFreq();
				int j;
				for(j = 0; j < NUMSLOTS; j++){
					if(findSlot(lowest) != -1){
						getBin(bin, lowest);
					}
					else{
						lowest = lowest-1;
					}
				}
			}
		}
		getWidget(bin);
	}
	printEarnings();
	printf("%d", lowestFreq());
	return 0;
	*/

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

