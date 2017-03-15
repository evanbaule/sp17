#include "floatx.h"

/*--------------------------------------------------------------------------------
	Return floatx representation (as defined by *def) which
	best approximates value
-------------------------------------------------------------------------------- */
floatx doubleToFloatx(const floatxDef *def, double value) {
	/* Put your code here */
	floatx bits = *(floatx*) &value;
	int fraction = def->totBits-def->expBits - 1;
	
	int exponent = 

	return ret;

}

/** Return C double with value which best approximates that of floatx fx
 *  (as defined by *def).
 */
double floatxToDouble(const floatxDef *def, floatx fx) {

	/* Put your code here */
	return NAN;
}