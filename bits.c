/* REMEMBER:
 * - This is the only file that you need to edit!
 * - Declare variables only at the beginning of a function (as in C89).
 * - Do not include <stdio.h> header (it confuses dlc)
 * - Check correctness with ./btest
 * - Check operator constraints with ./dlc bits.c
 * - Run ./grade before you commit/push your solution
 */

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 1
 *   Rating: 1
 */
int tmin(void) {
  return (1 << 31);
}

/*
 * bitOr - x|y using only ~ and &
 * (tip: always remember De Morgan's laws!)
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 4
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~((~x) & (~y));
}

/*
 * negate - return -x
 * (tip: remember the definition of two's complement!)
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int negate(int x) {
  return (~x + 1);
}

/*
 * isEqual - return 1 if x == y, and 0 otherwise
 * (tip: which bitwise op computes the difference?)
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x^y);
}

/*
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000,0x80000000) = 1,
 *            subtractionOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 3
 */
int subtractionOK(int x, int y) {
  int diff = x + ~y + 1;
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int sign_diff = diff >> 31;
  return (!(sign_x ^ sign_y) | !(sign_diff ^ sign_x));
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int min = (x + ~0x2F);
  int max = (x + ~0x39);
  return (!(min >> 31)) & (max >> 31);
}

/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum negative value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 4
 */
int satAdd(int x, int y) {
  // int oflow=(x^(x+y))>>31;
  int sum = x + y;
  int oflow_sign = ((x^sum)&(y^sum))>>31;
  int max = (oflow_sign << 31);
  int min = (sum >> (oflow_sign & 0x1F));
  //if (oflow_sign) {
  //  return sum >> 31;
  //}
  return min + max;
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int dividePower2(int x, int n) {
  int sign_check = (((x >> 31) & 0x01)<<n)+(x>>31);
  return ((x+sign_check)>>n);
}

/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int c_ = c << (n << 3);
  int mask = ~(0xFF << (n << 3));
  return (x&mask)+c_;
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 5
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  unsigned abs = uf & 0x7FFFFFFF;
  if (abs > 0x7f800000) {
    return uf;
  }
  return abs;
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 19
 *   Rating: 3
 */
int floatIsEqual(unsigned uf, unsigned ug) {
  int mask = ~(1 << 31);
  if (((uf & 0x7FFFFFFF) > 0x7F800000) || ((ug & 0x7FFFFFFF) > 0x7F800000)) {
    return 0;
  }
  if (((uf&mask) == 0) && (ug&mask)==0) {
    return 1;
  }
  return (uf==ug);
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 13
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int check = (uf>>23)&0xFF;
  int val = uf & 0x80000000;
  if (uf == 0x80000000){
     return uf;
  }
  if ((uf&0x7F800000) == 0x7F800000) {
    return uf;
  }
	if((uf&0x7F800000) == 0) {
		return ((uf<<1) | val);
	}
  if (++check == 0xFF) {
    return (0x7F800000|val);
  }
	return (uf + 0x00800000);
}
