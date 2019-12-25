#include <string>
#include <cstdio> 

class LFSR  {
public:
	LFSR( std::string seed, int t); // constructor to create LFSR with the given initial seed and tap
	
	/* THE STEP() FINCTION SIMULATES ONE STEM OF THE LFSR AND RETURNS THE RIGHTMOST BIT AS
		AN INTEGER (0 OR 1) 
	*/
	int step();


	/* SIMULATE K STEPS AND RETURN K-BIT INTEGER */
	/* THE MEMEBER FUNCTION GENERATE() TAKES AN INTEGER K AS AN ARGUMENT AND RETURNS A 
	   K-BIT INTEGER OBTAINED BY SIMULATING K STEPS OF THE LFSR. THIS TASK IS EASY TO
	   ACCOMPLISH WITH A LITTLE ARITHMETIC: INIALIZE A VARIBLE TO ZERO AND, FOR EACH BIT
	   EXTRACTED, DOUBLE THE VARIABLE AND ADD THE BIT RETURNED BY STEP().
	*/
	int generate(int k);

	/* STRING REPRESENTATION --> OVERLOAD THE << STREAM INSERTION OPERATOR TO DISPLAY ITS
		CURRENT REGISTER VALUE IN PRINTABLE FORM
	*/

	/* ADDITIONAL MEMBER FUNCTION*/
	//void displayStep();

	friend std::ostream& operator<< (std::ostream& out, const LFSR &lfsr);

	/* SPACE FOR POSSIBLE CONSTRUCTOR IF NEEDED */

private:
	std::string stringSeed;
	int tabBit; 
};
