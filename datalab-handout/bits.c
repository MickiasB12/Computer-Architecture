/* 
 * CS:APP Data Lab 
 * 
 * Mickias Bekele
 * USERID: mib222
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) { //param: x, y (int)
    int result;
    result = ((~x) & (~y)); //demorgans law of ~(x|y)
    return result; //return result
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) { //param: x (int)
    int boolean;
    int y;
    y = !x; //find the logical negation of the argument to check if it's zero
    boolean = !(x+x); //logical negation of their sum to check if it is Tmin
    boolean = ~(boolean & y) & ~((~boolean) & (~y)); //0 if is not Tmin or 1 is
    return boolean;
}
//2
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) { //param: x (int)
    int shift;
    int check;
    shift= 0xAA; //8 bits with all 1 bits on odd position
    shift = shift | shift << 8; //bitor with another allOddbits of 16 bits
    shift = shift | shift << 16; //24 bits
    shift = shift | shift << 24; //finally 32 bits
    check = !(~(~shift|~x) ^ shift); //bitAnd with shift itself and then find their difference, return 0 if there is a difference or 1 if there is not
    return check;
    
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { //param: x (int)
    int negateValue = (~x) + 1; //its the same as -x
    return negateValue; //return
    
}
//3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) { //param: x, y, z (int)
    int first;
    int second;
    int third;
    first = (0xFF | (0xFF << 8) | (0xFF << 16) | (0xFF << 24)) + !x; //creating 64 bits all 1s and adding with negate
    second = ~(first|(~z)); //bitAnd of first and int z
    third = second | (~(~first|~y)); //for the third one, to check if there is an int in x
    return third; //return
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) { //param: x (int)
    int firstNum;
    int final;
    firstNum = (x << 2) + x; //multiply by 5
    final = (firstNum + (~(~(firstNum >> 31) | ~(7)))) >> 3; //divide by 8 and round toward 0
    return final; //return
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) { //param: x (int)
    int result;
    int shifter;
    int adder;
    adder = ~x + 1; //find the negate of x
    shifter = ((x | adder) >> 31); //to check if it is 0 or not
    result = shifter + 0x01; //add one
    return result;
}
//float
/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) { //param: uf (unsigned)
    unsigned result;
    unsigned Nan = (0xFF) << 23; //to check if the exponent is all one's
    int x = (Nan & uf); //to check if their exponent is all one's
    int y = uf & ((0x00000010 << 19) + 0xFFFFFFFF); //to check if they have have at least 1 in their fraction
    if ((x == Nan) && (uf & y)) { //Nan value
        result = uf; //argument
    }
    else{
        result = uf ^ (0x00000008 << 28); //do the float negation
    }
    
    return result; //return
}
/* 
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug) { //param: uf, ug (unsigned)
    unsigned floatMask = 0xFFFFFFFF + (0x00800000); //for fraction masking
    unsigned x = 0x7FFFFFFF & uf; //to check for uf
    unsigned y = 0x7FFFFFFF & ug; //to check for ug
    if ((((x >> 23) == 0x000000FF) && (~(~floatMask | ~uf) != 0))) { //if they are either Nan or infinity
            return 0; //return 0
    }
    else if (((y >> 23) == 0x000000FF) && (~(~floatMask | ~ug) != 0)){ //for ug the same
        return 0; //return 0
        
    }
    else if ((x == 0) && (y == 0)) { //if all them is 0 (both +0 and -0)
        return 1; //return 1
    }
    else{
        return uf == ug; //otherwise return their equality
    }
    
}
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) { //param: uf (int)
    unsigned result;
    unsigned Nan = ((uf>>23) & 0xFF); //to check for Nan
    switch(uf){
        case 0x0: //if uf is 0
            result = uf; //return 0
            break;
        case 0x80000000: //if uf -0
            result = uf; //return 0
            break;
        default:
            switch(Nan){
                case 0xFF: //if it is Nana
                    result = uf; //return uf
                    break;
                case 0: //no common point with 0xFF (denormalized)
                    result = ~((~uf | 0x7FFFFFFF) & ~(uf<<1)); //perform operation
                    break;
                default: //else if it is normalized
                    result = uf + (0x00800000); //perform the double operation
            }
    }

    return result; //return result
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) { //param: uf (unsigned)
    unsigned lastBit;
    unsigned first8Bits;
    unsigned result;
    lastBit = uf >> 31; //to check the sign
    first8Bits = (uf >> 23);
    first8Bits = first8Bits & 0xFF; //for the Nan part
    switch(first8Bits){
        case 0x7F800000: //if all exponents is one and at least there is 1 in fraction
            return 0x80000000u; //return 0
            break;
        default:
            if(first8Bits < 127 || !first8Bits){ //if the shift is less than bias
                return 0x0; //return 0
            }
            else{
                first8Bits = first8Bits - 127; //subtract the bias
                if(first8Bits > 30){ //if the number is greater than or equal to 31
                    return 0x80000000u; //return 0
                }
            }
    }
    if(first8Bits <= 22){ //if the result is between 0 and 22
        result = ((uf & 0x7FFFFF)) >> (23 - first8Bits); //perform the operation of arthimetic right shfit by the difference between 23 and first8Bits
    }
    else{
        result = (uf & 0x7FFFFF) << (first8Bits - 23); //perform left shift by the difference of first8Bits and 23
    }
    result = result + (1 << first8Bits); //add one to for the exponent

    if (lastBit == 0x01){ //if it is negative
        result = ~result + 1; //find the negate
    }
    return result;
}
