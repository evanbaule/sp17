#include "slots.h"
#include <stdio.h>


#define ARRLEN 100
#define MAX 2147483647

int lowestFreq();
int frequency[ARRLEN];

int main(int argc, char ** argv) {

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
		
		/*if(findSlot(bin) == -1){
			getBin(bin,idx);
			if(idx < 3){
				idx++;
		}else {
				l = lowestFreq();
				int j;
				for(j = 0; j < NUMSLOTS; j++){
					if(findSlot(l) != -1){
						getBin(bin, j);
					}
					else{
						l = l-1;
						lowestFreq(l);
					}
				}
			}
		}
		*/

		
		getWidget(bin);
	}
	printEarnings();
	printf("%d", lowestFreq());
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

