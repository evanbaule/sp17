#include <stdio.h>

//The following variables were used for testing
#define ii = 1234; //31: "onethousandtwohundredthirtyfour" 
#define iic = 1212; //17 "onethousandtwelve"
#define ib = 1000000000; //10 "onebillion"

int onesPlace[10] = {
	4, //zero mainly for ph to get same index as number
	3, //one
	3, //two
	5, //three
	4, //four
	4, //five
	3, //six
	5, //seven
	5, //eight
	4, //nine
}

int places[5] = {
	4, //teen
	7, //hundred
	8, //thousand
	7, //million
	7, //billion
}

int corner[4] = {
	3, //ten
	5, //eleven
	6, //twelve
	8, //thirteen
}

int calculate(int inp);

int main(){
	/*
	Operational Flow:
		1. Reads in an integer value from the std in stream, bound to inputInt
		2. Loops through the inputInt and saves its amount of digits to digitCtr
		3. Constructs an array of len[digits]
		4. Loops through that array backwards, adding to the output integer the number of character as found by the 'library' above.
		5. Prints the total value to the screen.
	*/
	printf("Welcome to the number converter!\n");
	printf("Please enter a number to be converted: \n")
	printf("Because this software is in testing, the default value is %d", ii);
 
 	//Variables to use
 	int out = 0;
 	int inputInt = ii;
 	int digits = 0;
 	int tcv = inputInt; //Temp Counter Variable
 	int tcv2 = intputInt; //Temp Counter Variable

 	//Determine how long the digit array needs to be
 	while(tcv != 0)
    {
        tcv /= 10;
        digits++;
    }

    //Executes real working code
    if(digits != 0){
    	int integerArray[digits]; //Read that a 0 len array is not allowed? thats why this is in here

    	//Populating array of digits
    	int i = 0; //ITERATOR
    	while(tcv2 != 0){
    		integerArray[i] = tcv2 % 10;
    		tcv2 /= 10;
    		i++;
    	}

    	//Works the array backwards to get the total
    	//Decided to loop this backwards instead of the other loop to save with inverting indexes
    	int j; 
    	for(j = (digits-1); j > 0; j--){
    		out += calculate(integerArray[j], j);
    	}

    } else {
    	out += 4;
    }



	return 0;
}

/*
Parameters (val, place)

*/
int calculate(int val, int place){
	int retVal = 0;
	return retVal;
}