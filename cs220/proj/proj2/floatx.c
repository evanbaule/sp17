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


	/* --------------------------------------------------------------------------
	Below: Init of all ints used for computation of floatx 
	----------------------------------------------------------------------------- */
	int dLen, //Length of standard double
		dExp, // Number of exponent bits in a standard double
		dFrac, // Number of fraction bits in a standard double
		fLen, //Total number of bits in our floatx return value, per spec
		fExp, //Number of fraction bits to be used in return floatx, per spec
		fFrac, //Number of exponent bits to be used in return floatx, calculated via spec
		dBias, //Value used to bias a double (1023)
	   	fxBias, //Value used to bias a custom floatx
	   	maxFloatx; //The maximum value of a floatx, used for representing numbers greater than we can handle

	dLen = sizeof(value) * 8; //Yields total length of a standard double (could hardcode 64 here)
	dExp = 11; 
	dFrac = 52; 

	fLen = def->totBits; 
	fExp = def->expBits;
	fFrac = fLen - fExp - 1;

	maxFloatx = pow(2, fExp) -1;

	/* Bias values for each data type*/
	dBias = pow(2, dExp-1) - 1;
	fxBias = pow(2, fExp-1) -1;
	
	

	/* --------------------------------------------------------------------------
	Below: Shifting Bits in order to isolate the 3 pieces of our return floatx
	----------------------------------------------------------------------------- */

	/* Variables to use in construction of returnFloatx */
	floatx 	retSign, //Sign Bit
			retExp, //Exponent bits
			retFrac, //Fraction bits
			copy;  //Our temporary value, allowing us to shift bits without worrying

	/*
	Sign Bit
		Make copy of the bit makeup for value
		Shift it 1 less than its total length, isolating the most significant bit -> the sign bit
	*/
	copy = makeup;
	copy >>= dLen - 1;
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
	copy >>= (dLen - fFrac - 1);
	//Rounding
	if((copy%2) == 1){
		copy += 0x1;
	}
	copy >>= 1;
	retFrac = copy;


	/* --------------------------------------------------------------------------
	Below: Evaluating Special Cases
	----------------------------------------------------------------------------- */

	/* Case 1: Values Too Large (Infinite) */
	if(retExp >= dBias || retExp >= fxBias){
		retExp = maxFloatx;
		retFrac = 0;
	} else {
		retExp += fxBias;
	}

	/* Case 2: Values Too Small (Denormalized) */
	signed long denExp = (signed long) retExp;
	if(denExp < 0){

	}




	/* --------------------------------------------------------------------------
	Below: Construction of our return value,
	a floatx representation of '@param: value'
	----------------------------------------------------------------------------- */
	/*  Add Sign Bit  */
	retSign <<= (fLen-1);
	returnFloatx += retSign;

	/*  Add Exponent Bits  */
	retExp <<= fFrac;
	returnFloatx += retExp;

	/*  Add Frac Bits  */
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

