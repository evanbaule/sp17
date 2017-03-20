#include "floatx.h"
#include <math.h>

/*--------------------------------------------------------------------------------
	Return floatx representation (as defined by *def) which
	best approximates value
-------------------------------------------------------------------------------- */
floatx doubleToFloatx(const floatxDef *def, double value) {
	/* Put your code here */
	floatx returnFloatx = 0;


	/* General Use Ints */
	int doubleLength, //Length of standard double
		dExp, // # of expbits in standard double
		dFrac, // # of fracbits in standard double
		fLen, //total # of bits from definition
		fExp, //number of fraction bits to be used in return floatx, taken from function call
		fFrac, //number of exponent bits in return floatx
		maxFloatx; //maximum value of a floatx;

	doubleLength = sizeof(value) * 8; //gives total length of a standard double
	dExp = 11; // # of expbits in a standard double
	dFrac = 52; // # of fracbits in a standard double

	fLen = def->totBits; //Pulling values out of the definition
	fExp = def->expBits;
	fFrac = fLen - fExp - 1;

	maxFloatx = pow(2, fExp) -1;

	int dBias, //bias for a double
	   	fxBias; //bias for a custom size floatx

	dBias = pow(2, dExp-1) - 1;
	fxBias = pow(2, fExp-1) -1;
	

	/* Variables to use in construction of returnFloatx */
	floatx 	retSign, //sign bit
			retExp, //exponent bits
			retFrac; //fraction bits

	floatx makeup = *(floatx*) &value; //Gives us the bit makeup of @value as a floatx
	floatx temp1 = makeup;
	floatx temp2 = makeup;

	//sign
	retSign = makeup >> (doubleLength-1); //gets sign bit

	//exp
	temp1 <<= 1; //chop off sign bit
	retExp = temp1 >> (dFrac + 1);
	retExp -= dBias; //biases the exponent by the double bias value 1023

	//frac
	temp2 <<= (dExp+1);  //leaves us with just exponent bits
	retFrac = temp2 >> (doubleLength - fFrac - 1);

	if((retFrac%2) == 1){
		retFrac >>= 1;
		retFrac += 0x1;
	} else {
		retFrac >>= 1;
	}

	//case: infinity
	if(retExp >= dBias || retExp >= fxBias){
		retExp = maxFloatx;
		retFrac = 0;
	} else {
		retExp += fxBias;
	}

	//case: denormal




	//build
	returnFloatx += retSign << (fLen-1);
	returnFloatx += retExp << fFrac;
	returnFloatx += retFrac;
	return returnFloatx;
}

/** Return C double with value which best approximates that of floatx fx
 *  (as defined by *def).
 */
double floatxToDouble(const floatxDef *def, floatx fx) {
	//wayyyyy less comments down here because a lot of the stuff is the same, especially vars
	/* Union used to copy over retvals */
	union{
		floatx f;
		double d;
	}u;

	floatx returnFloatx = 0; //use this and then copy over the 

	/* size trackers */
	int dLen,
		dExp,
		dFrac,

		fLen,
		fExp,
		fFrac;

	/* double specs */
	//double d = 0; //just to grab size
	dLen = 64; 
	dExp = 11; 
	dFrac = 52; 

	/* floatx specs */
	fLen = def->totBits; 
	fExp = def->expBits;
	fFrac = fLen - fExp - 1;

	/* values used for biasing exponents */
	int dBias,
		fBias;

	dBias = pow(2, dExp-1) - 1;
	fBias = pow(2, fExp-1) -1;

	// dec some temps to use below
	floatx t1 = fx; 
	floatx t2 = fx;

	floatx  fretSign,
			fretExp,
			fretFrac;

	fretSign = fx >> (dLen - 1);

	t1 <<= 1;
	fretExp = t1 >> (dLen - fExp);
	fretExp -= dBias; // -= 1023

	t2 <<= (fExp+1);  //leaves us with just exponent bits
	fretFrac = t2 >> (dExp + 1);

	
	returnFloatx += fretSign << (dLen-1);
	returnFloatx += fretExp << dFrac;
	returnFloatx += fretFrac;
	u.f = returnFloatx;
	return u.d;

}

