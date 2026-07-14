/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */




/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */


int sign(int x) {
/*
EitherPosOrNeg checks for that by just shifting the numbers, eihter all 1's (-1) or all 0 (0)
is_nonZero checks for any number but zero and returns -1 if that is true. getting the not of 0 + 1 just give 0 again. 
means that nonzero gives (-1)
0 gives 0
return gives a few cases
if positive number
0 | -1 & 1 (which is 1 because -1 is all ones) = 1
if zero 
0 | 0  & 1(which is 0 because 0 is all 0's no match with 1) = 0
if negative
-1 | -1 & 1 (which is 1, reason above) = -1 (because -1 | 1 doesnt change anything, or 1 cannot add anything to something all 1s)
*/
  int isEither_Pos_And_0_OR_Neg = x >> 31;
  int is_NonZero = (x |(~x + 1)) >> 31;
  return isEither_Pos_And_0_OR_Neg|(is_NonZero & 1) ;
}





/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
/*
so will want to built a bit mask, but cannot use number larger than 255
can built with shifting maybe?
255 is 1111 1111
so can do 01 then just shift and or it until we get the full mask
the bit mask is then used in NOT to get ONLY even numbers, then just checking if its non zero (meaning at least a 1 in an even bit) 
*/
  //construct bitmask of even numbers without technically calling a larger number than 255?
  int bmask = 1;
  int bmask = bmask | (bmask << 2);
  bmask = bmask | (bmask << 4);
  bmask = bmask | (bmask << 8);
  bmask = bmask | (bmask << 16);

  // Isolate even bits
  int even_bits = x & bmask;
    
  // Use non-zero shift from the othe rone!!!
  // gives -1 if any even bits are active, 0 if none are
  int evens_exist = (even_bits | (~even_bits + 1)) >> 31;
    
  // Turn  -1 into a 1
    return evens_exist & 1;
}





/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  // ~0 is -1, all the zeros flip to ones, meaning that its -1, 
  return ~0;
}





/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
/*
 * highbit shifting right comes with the problem of padding all ones, which does nothing to help with the bit masking
 * so my idea is to just invert the number and left shift it.
 */
  int targetHighMask = 32 + (~highbit +1 );

/*
 * create a block of ones (i.e ~0 i.e -1)
 * shift all those ones left by the target high mask.
 * this means that we are left with 1's on the far left , however many there need be for highmask
 * we invert this so that we can later push it back by the same amount of highbits to the right
 */
  int highmask = ~(~0 << targetHighMask);
  
// this is where things get pushed all the way to the right, with no leading 1's, thus creating the highmask.
// we need to do target number for the ask -1 for this calculation to be correct
  highmask = highmask >> (targetHighMask + ~0);
  
  //lowbit is easy
  int lowmask = ~0 << lowbit;

  //combine them together! 
  int mask = highmask & lowmask;

  return mask;
}






/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/*
 * 8 bits in 1 byte in 32 arch
 * I will shift n to the left 3 times to get n * 8, that number will be the amount of bits we have to shift
 * Then, we just shift to the left by that many bits, we'll have our value wanted at the leftmost.
 * we can then just use AND to wipe out the unwanted numbers to the right. 
 * because we only need the first 8 bits, we can use number 255 (0's followed by eight 1s.)to take out th other stuff
 */

 int shiftBits = n << 3;
 int shiftWord = x >> shiftBits;
 int extraction = shiftWord & 255;
  return extraction;
}



/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  // need to just take the sign as a mask then 
  // minus by the mask in the end if there is anything
  mask = x >> 31;
  //this leaves us with either 0 or -1
  // means that we subtract either 0 or 1
  val = x + mask;
  // use an XOR to flipt the bits,
  // if positive value then everything stays teh same 
  // if neg then flips
  return val ^ mask;
}






/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */

 /* Found this sample of couting bits on stackoverflow
c = (v & 0x55555555) + ((v >> 1) & 0x55555555);
c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
c = (c & 0x0F0F0F0F) + ((c >> 4) & 0x0F0F0F0F);
c = (c & 0x00FF00FF) + ((c >> 8) & 0x00FF00FF);
c = (c & 0x0000FFFF) + ((c >> 16)& 0x0000FFFF);
USING THIS BUT EDITING IT TO FIT THE CRITERIA HERE
  */
int bitCount(int x) {
  // building 0x555... with the same trick we did to get larger numbers than 255
  int mask1 = 0x55 | (0x55 << 8);
  // so this now becomes 0x5555
  mask1 = mask1 | (mask1 << 16);
  //this becomes 0x55555555

  // same with 0x333...
  int mask2 = 0x33 | (0x33 << 8);
  mask2 = mask2 | (mask2 << 16);
  
  int mask3 = 0x0F | (0x0F << 8);
  mask3 = mask3 | (mask3 << 16);

  x = (x & mask1) + ((x >>1) & mask1);
  // so this masks every other bit
  // then added by the same thing happening but shifted 1 to the left
  // this essentially groups bits into 2 when adding them together

  x = (x & mask2) + ((x >>2) & mask2);
  // this is the same thing but groupting them into 4s now

  x = (x & mask3) + ((x >>4) & mask3);  
  //now 8s!

  x = x + (x >> 8);
  //16s, no mask needed

  x = x + (x >> 16);
  //32, now this sSHOULD be our number of 1's

//need a way to capture only up to 32, which is going to be six individal bits from the leftmost
  return x & 0x3F;

}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    return 2;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return 2;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void){
//hopefully i understood this correctly? just shifting 1 to the most sig bit (right) to get the Biggest negative?
  return 1 << 31;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  return 2;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
 
  // make sure that sign bit is stored somewhere, 
  // then mask out the sign bit, make sure its always 0
  // then right shift the whole thing
  // then add back in the -1 later?
    return 2 ;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  return 2;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  int !(x >> 31);
  //-1 turns into 0, 0 turns into 1
  // need to handle 0 too
  //double bang to check if x is 0, if it is then it will return 0 because of the AND :D 
  return x & (!!x);
}
