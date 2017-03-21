#include "floatx.h"
#include <math.h>

/*--------------------------------------------------------------------------------
	Return floatx representation (as defined by *def) which
	best approximates value
-------------------------------------------------------------------------------- */
floatx doubleToFloatx(const floatxDef *def, double value) {
	/* Put your code here */
	floatx returnFloatx = 0;
	floatx makeup = *(floatx*) &value; //Gives us the bit makeup of @value as a floatx


	/* Init of all ints used for computation of floatx */
	int doubleLength, //Length of standard double
		dExp, // # of expbits in standard double
		dFrac, // # of fracbits in standard double
		fLen, //total # of bits from definition
		fExp, //number of fraction bits to be used in return floatx, taken from function call
		fFrac, //number of exponent bits in return floatx
		maxFloatx, //Maximum value of a floatx
		dBias, //bias for a double
	   	fxBias; //bias for a custom size floatx; //maximum value of a floatx;

	doubleLength = sizeof(value) * 8; //gives total length of a standard double
	dExp = 11; // # of expbits in a standard double
	dFrac = 52; // # of fracbits in a standard double

	fLen = def->totBits; //Pulling values out of the definition
	fExp = def->expBits;
	fFrac = fLen - fExp - 1;

	maxFloatx = pow(2, fExp) -1;

	/* Bias values */
	dBias = pow(2, dExp-1) - 1;
	fxBias = pow(2, fExp-1) -1;
	
	/* Variables to use in construction of returnFloatx */
	floatx 	retSign, //sign bit
			retExp, //exponent bits
			retFrac; //fraction bits

	/* Shifting to Isolate 3 parts of the floatx necessary for construction */
	
	/*
		Sign Bit
			Make copy of the bit makeup for value
			Shift it 1 less than its total length, isolating the most significant bit -> the sign bit
	*/
	floatx copy = makeup;
	copy >>= doubleLength - 1;
	retSign = copy; 

	/*
		Exponent Bits
			Reset the copy temp
			Shift it to the left once to eliminate the sign bit
			Shift it to the right 1 more than the total amount of fraction bits, isolating the exponent bits
			Bias the exponent bits by subtracting 2^(dFrac-1)-1  (subtract 1023)
	*/
	copy = makeup; //reset copy
	copy <<= 1; 
	copy >>= (dFrac + 1);
	copy -= dBias; // -= 1023
	retExp = copy;

	/*
		Fraction Bits
			Reset the copy temp
			Shift left once to eliminate the sign bit
			Shift left again to eliminate the exponent bits (these could be done simultaneously, but I seperated them to clean it up)
			Shift all the way right to isolate only the fraction bits

	*/
	copy = makeup; 
	copy <<= 1;
	copy <<= (dExp);  
	copy >>= (doubleLength - fFrac - 1);
	retFrac = copy;

	if((retFrac%2) == 1){
		retFrac += 0x1;
	}
	retFrac >>= 1;

	//case: infinity
	if(retExp >= dBias || retExp >= fxBias){
		retExp = maxFloatx;
		retFrac = 0;
	} else {
		retExp += fxBias;
	}

	//case: denormal
	signed long denExp = (signed long) retExp;
	if(denExp < 0){

	}




	//build
	/* -- Add Sign Bit -- */
	retSign <<= (fLen-1);
	returnFloatx += retSign;

	/* -- Add Exponent Bits -- */
	retExp <<= fFrac;
	returnFloatx += retExp;

	/* -- Add Frac Bits -- */
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

	fx <<= (dLen - fLen);

	/* values used for biasing exponents */
	int dBias,
		fBias;

	dBias = pow(2, dExp-1) - 1;
	fBias = pow(2, fExp-1) - 1;

	// dec some temps to use below
	floatx t1 = fx; 
	floatx t2 = fx;
	
	/* -- Used to build final return value -- */
	floatx  fretSign,
			fretExp,
			fretFrac;

	/* -- Return Value Sign Bit  -- */
	fretSign = fx >> (dLen - 1);

	/* -- Return Value Exponent Bits  -- */
	t1 <<= 1;
	fretExp = t1 >> (dLen - fExp);
	fretExp -= fBias;

	/* -- Return Value Fraction Bits  -- */
	t2 <<= (fExp+1);  
	fretFrac = t2 >> (dExp + 1);

	// case: infinity
	if(fretExp >= dBias || fretExp >= fBias){
		return INFINITY;
	} else {
		fretExp += dBias;
	}
	

	/* -- Build Return floatx -- */
	returnFloatx += fretSign << (dLen-1);
	returnFloatx += fretExp << dFrac;
	returnFloatx += fretFrac;

	/* -- Return -- */
	u.f = returnFloatx;
	return u.d;


}

