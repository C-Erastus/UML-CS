/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Erastus Toe
Hours to complete assignment: 5
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/

 In this assignment I simulated a linear feedback shift register
 This was implemented two member functs (1) step and (2) generate. 
 The step functions basically did the LSFR and the generate function
 called the step functions. 



/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
 I used a string for the bits representation. In my step function I created
 a temp string and took all the bits from the seed and push it into temp
 with the exception of the drop off bit. Then I XOR the tab bit and the
 drop off bit.

 To find the tab bit, I had to subtract the tab bit from the size of the 
 seed. And then subtract 1 from that result. 

 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
I tested my step function to make sure it returns the correct bit.
I also tested my generate function to make sure it returns the correct




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I didn't get any help. I had to figure it out all by myself

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

I really didn't encountered any serious problem. It did take longer than 
usual to understand what I was doing. But once I understood the assigmnet
It was easy to implement.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

 we should do less reed me. 

