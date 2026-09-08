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
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    // This works but less natural.
    // // "0, 0" 조합만 제외하면 & 후 ~으로 다 된다.
    // int process_except_00 = ~(x & y);
    // // 이후 "0, 0" 조합만 제거해버리면 된다.
    // int remove_00 = ~(~x & ~y);
    //
    // return (process_except_00 & remove_00);

    int keep_only_11 = x & y;
    int keep_only_00 = ~x & ~y;
    // 각각 11과 00 조합이었던것만 살려놨으면 양쪽 모두 만족하는 것은 01, 10 뿐이다.
    return (~keep_only_00 & ~keep_only_11);
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    return (1 << 31);
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    // try: 1
    // int two_complement = ~(x + 1) + 1;
    // int msb_only = (((x + 1) & two_complement) >> 31) & 1;
    // return (msb_only);

    // try: 2
    // return (!(~((x + 1) ^ x)));

    // try: 3
    // int plus_one = x + 1;
    // int plus_one_two_comp = ~plus_one + 1;
    // int mask_msb =

    // try: 4
    // 0이 아니면서 "2의 보수"가 자기 자신과 같은 수
    int n = x + 1;
    int zero_if_n_zero = !!n & 1;
    int n_two_compl = ~n + 1;
    int is_self_two_compl = (!(n ^ n_two_compl)) & 1;
    return (zero_if_n_zero & is_self_two_compl);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    // 1. 몇 칸 만큼 차지하는지 알면 shift 연산 후 10101010..10과 함께 정확히 일치하는지 비교해서 확인할 수 있다.
    // 2. 1010...10은 0101...01을 2배 한 값이다.
    // 3. (msb-1 미만의 비트만 사용한 1 이상의) 값에 << 연산을 한 번 해주면 2배가 된다.
    // int mask_08bit = 0b10101010;
    int mask_08bit = 0xAA;
    int mask_16bit = (mask_08bit << 8) | mask_08bit;
    int mask_32bit = (mask_16bit << 16) | mask_16bit;
    int x_after_mask = x & mask_32bit;
    return !(x_after_mask ^ mask_32bit);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return (~x + 1);
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
    // 임의의 수가 10보다 크거나 같은지 확인하려면 10을 뺀 값이 음수인지 확인하면 된다.
    int min = 0x30;
    int max = 0x39;
    int is_more_or_equal_than_min = !((x + (~min + 1)) >> 31 & 1);
    int is_less_or_equal_than_max = ((x + (~max + 0)) >> 31 & 1);
    return (is_more_or_equal_than_min & is_less_or_equal_than_max);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    // x를 0b00..0 또는 0b11..1로 만들어서 두 operand를 마스킹한다. 그럼 한쪽은 어차피 0이 되니까 그냥 OR(`|`) 해주면 그만
    int process_x = ((!!x << 31) >> 31);
    int process_y = process_x & y;
    int process_z = ~process_x & z;
    return (process_y | process_z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    int is_same_sign = !((x ^ y) >> 31);

    // x가 더 크면 0을 리턴
    // => if (y - x < 0) && return (0);
    // 음수인지 확인은 msb로
    int difference = y + (~x + 1);
    int is_difference_negative = (difference >> 31) & 1;

    //  y가 양수일 때만 참
    int when_sign_diff = !((y >> 31) & 1);

    return (is_same_sign & !is_difference_negative) | ((!is_same_sign) & when_sign_diff);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
    // 나의 접근법: x가 0인 경우와 그렇지 않은 모든 경우를 구분하는 방법은
    //  x와 x의 2's complement의 &연산 결과가 0인지 확인하는 것이다.
    //  따라서 이를 수행한 뒤에 0은 1로, 0이 아닌 것은 1로 만드는 연산을 수행하면 될 것 같다.
    //  0의 보수는 여전히 0인 점을 활용해 보수를 `|` 연산 해준다. 그럼 0이 아닌 애들은 msb가 항상 1이된다.
    int classify_zero = x | (~x + 1); // 0 또는 0이 아닌 애들로 구분됨
    return ((~classify_zero >> 31) & 1); // 반대로 출력해야하니까 비트 반전을 하고, msb를 lsb로 몰아넣고난 뒤에 반환
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    // try: 1
    // 일단 음수는 생각을 못했어. msb가 0이라는 가정하에,
    //  >> 연산을 31회 수행하며 count를 1씩 누적해가고
    //  이때 lsb의 값이 1이면 flag를 true로 만들고 이때 count로 반환값을 갱신한다.
    //  근데 이러면 31 * operator라서 일단 안되겠는데?
    //  접근 방법이 옳다면 효율화를 고민해보자.
    // int count = 0;
    // int flag;
    // int result;
    //
    // count = count + 1;
    // flag = x & 1;
    // result = ((!!flag << 31) >> 31) & count;
    // x = x >> 1;

    // try: 2 helped by deepseek
    // 1. 부호 비트의 필요 여부
    // 2. 이외의 최상위 비트는 몇번째 위치에 등장하는가?
    //      즉, 31회 비트를 옮겨보면서 1인지 확인하면 될 듯?
    // WRONG: 30회 shift연산을 하며 "0 or k"를 31개 도출하더라도 그것들을 어떤 연산자로 묶더라도 최상위 하나만 남길 방법이 없다.

    // try: 3 helped by deepseek
    // 1. (부호 비트를 제외하고)하나의 N번째 비트가 1이라는 것이 의미하는 바는 값이 최소 2^(n-1) 이상의 값이라는 것을 의미한다.
    //    하위 비트가 1이든 0이든 상관없어.
    // ?. 일단 음수인지 판단해서 양수로 만들고 각 비트가 1일때의 최소값들을 빼줘볼까? 최소값보다도 작으면 해당 비트 자리수는 의미 없으니까
    // ?. 이분탐색으로 절반씩 탐색하며 최대 위치의 1을 찾아본다.
    //      ?. 일단 양수로 만들기 vs 적절히 마스킹하기
    //         1. 일단 양수 -> shift연산 해도 오염되지 않아서 편리하다.
    //         2. 적절히 마스킹 -> 어차피 masking 되면 의미 없다. -> 이게 나은듯?
    //      ?. 근데 이분탐색 하려면 판단 후 좌/우 어느방향 shift인지 판단을 해야하는데?? 말이되나
    //

    // try: 4 helped by deepseek
    // 1. 일단 부호비트 버려주면서 따로 처리
    // 2. (부호비트 떼어낸 채로)최상위 비트 자리수를 이분탐색으로 찾기
    // 3. 이때 최상위 비트란 양수인 경우 1을 찾아주고, 음수인 경우 0을 찾아주면 된다.
    //      양수인 경우 1이 (자리수로서) 의미있고, 음수인 경우 0이 (자리수로서) 의미있기 때문.

    int a = 1 << 16;
    int b = 1 << 8;
    int c = 1 << 4;
    int d = 1 << 2;
    int e = 1 << 1;
    int is_less_then_a;
    int mask_a;
    int is_less_then_b;
    int mask_b;
    int is_less_then_c;
    int mask_c;
    int is_less_then_d;
    int mask_d;
    int is_less_then_e;
    int mask_e;

    int is_negative = (x >> 31) & 1;
    int x_mask = ((!is_negative << 31) >> 31); // x가 양수이면 111..1, 아니면 000..0. 음수이면 반대로
    int _x = (x_mask & x) | (~x_mask & ~x); // 최상위 비트란 양수인 경우 1을 찾아주고, 음수인 경우 0을 찾아주면 된다.
    // pintf("%#034b, %d\n", _x, _x);

    int result = 0;

    is_less_then_a = ((_x + (~a + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_a = ((!is_less_then_a << 31) >> 31);
    _x = _x >> (16 & mask_a);
    result = result + (16 & mask_a);
    // pintf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_a, result);

    is_less_then_b = ((_x + (~b + 1)) >> 31) & 1;
    mask_b = ((!is_less_then_b << 31) >> 31);
    _x = _x >> (8 & mask_b);
    result = result + (8 & mask_b);
    // pintf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_b, result);

    is_less_then_c = ((_x + (~c + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_c = ((!is_less_then_c << 31) >> 31);
    _x = _x >> (4 & mask_c);
    result = result + (4 & mask_c);
    // pintf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_c, result);

    is_less_then_d = ((_x + (~d + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_d = ((!is_less_then_d << 31) >> 31);
    _x = _x >> (2 & mask_d);
    result = result + (2 & mask_d);
    // pintf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_d, result);

    is_less_then_e = ((_x + (~e + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_e = ((!is_less_then_e << 31) >> 31);
    _x = _x >> (1 & mask_e);
    result = result + (1 & mask_e);
    // pintf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_e, result);
    // result = (((!!result << 31) >> 31) & (result + 1 + 1)) | (((!result << 31) >> 31) & 1);// 양수든 음수든 부호 비트 하나는 필요하고, 아래 방식이면 자리수가 1비트 만큼 덜 표현된다.
    result = 1 + (((!!result << 31) >> 31) & (result)) + _x; // 부호 비트 + 누적 result + _x(1 or 0)
    return (result);
}
// float
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
unsigned floatScale2(unsigned uf)
{
    // 1~8번째 비트를 1 키운다.
    int exponent_field_masking = ((0x7F << 1) + 1) << 23;
    // printf("%#034b\n", exponent_field_masking);
    int exponent_field_value = (uf & exponent_field_masking) >> 23;

    int fraction_field_masking = (1 << 23) - 1;
    int fraction_field_value = uf & fraction_field_masking;
    // printf("%#034b\n", fraction_field_masking);
    int sign_masking = 1 << 31;
    int sign_bit = uf & sign_masking;

    int is_NaN = (exponent_field_value == 0xFF) && (fraction_field_value != 0);

    // case: 0x80000000 -> 음수 0에 해당하는 실수. 그대로 음수 0을 리턴해야한다.
    int is_zero = (exponent_field_value == 0) && (fraction_field_value == 0);
    // printf("is_zero? %d\n", is_zero);

    // case: 0x80_0000 -> 0  000_0000_1  000_0000_0000_0000_0000_0000
    // 1.f = 1.0 * 2^{-126}   -> 0x010000...

    // case: 0x1 -> 0  000_0000_0  000_0000_0000_0000_0000_0001
    int is_denormal = exponent_field_value == 0x00;

    // case: 0x7f800000  ->  0 111_1 1111 000_....
    int is_infinit = exponent_field_value == 0xFF;

    if (is_zero)
        return (uf);

    if (is_NaN)
        return (uf);

    if (is_denormal)
        return (((uf << 1) >> 1) * 2) | sign_bit;

    if (is_infinit)
        return uf | sign_bit;

    // normal case: exponent+1 to double
    return (uf & ~exponent_field_masking) | (exponent_field_value + 1) << 23;
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
int floatFloat2Int(unsigned uf)
{
    // int casting means discarding the part under a point.
    // then the key of this question is finding the point using exponent.
    // e == 0 -> 23개 버림
    // e == 1 -> 22개 버림
    // e == 2 -> 21개 버림
    // 즉,  e <= 0 다 버림
    // else 23 - e 만큼 버림
    int s_mask = 1 << 31;
    int e_mask = 0xFF << 23;
    // int f_mask = (1 << 23) - 1;

    int exponent = ((uf & e_mask) >> 23) - 127;
    // printf("expo: %d\n", exponent);
    // int fraction = uf & f_mask;

    int casting_mask = (1 >> 23) & 1 << (exponent <= 23 ? 23 - exponent : 0);

    // 예외처리
    int is_exponent_field_all_1 = ((uf & e_mask) >> 23) == 0xFF;

    // printf("0\n");
    if (is_exponent_field_all_1)
        return (0x80000000u);

    // case: 0x80000000  ->  1 000_0 000_0 000_....
    // case: 0x80800000  ->  1 000_0 000_1 000_....
    // 음수 0에 해당하는데, int 타입엔 음수 0같은것은 없으니 그냥 0으로 만들어야한다.
    //
    // case: 0x7f_ffff  ->  0 000_0 000_0 111_1111__1111_1111_....
    // denormal에 fraction은 0.111...(23)..1
    // denormal은 그냥 0과 0.x사이니까 sign도 없이 0 리턴해야지.
    if (exponent < 0)
        return 0;

    // case: 0x3f800000  ->  0 011_1 111_1 000_....
    // normalized number에 2^{0}을 곱하는 셈이니, 부호만 유지한 채 1을 리턴해야한다.
    // case: 0xbf800000  ->  1 011_1 111_1 000_...
    // 이때 음수는 2의 보수를 구해줘야한다.
    // printf("2\n");
    if (exponent == 0)
    {
        if (((uf & s_mask) >> 31) == 0) // 양수라면
            return (1);
        else
            return (-1);
    }

    // printf("3\n");
    // if (exponent <= 23)
    if (exponent < 31)
        return uf & casting_mask;

    // case: 0x7f000000  ->  0 111_1 111_0 000.....
    // 지수가 크다면 값을 키워줘야한다.
    // anything out of range ...
    // 2^31 이상부터 overflow 그냥 overflow다. 즉, e >31
    return (0x80000000u);
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    // s_field = 0 (무조건 0 이상이다)
    // f_field = 0x000...(23)..0  -> normalized value == 1.0
    // e_field = 0x이걸로 배수 조절. x + bias
    //  그럼 normal구간, denormal 구간이 따로 고려되야할듯
    int bias = 0x7F;
    int exponent = (x + bias) << 23;
    int postive_infinity = 0xFF << 23;

    // case: 0x8000_0000 -> 0
    // 이놈은 음수로 너무 크다. 즉, denormal로 표현하기에도 한계가 있다.
    // 본래 denormal이란 2^{-126} * 0.xxxx..(23)..x
    // 즉, x가 -127일때도 가능. 언제까지? 23번까지는 표현할  수있어.
    if (x < -127 - 23)
        return (0);

    // case: 0x800000 -> 0x7f80_0000  -->  0 111_1 111_1 000_0000_....
    // 어랍쇼 지수가 너무 큰데요?
    if (x >= 128)
        return (postive_infinity);

    // case: 31 -> 0x4f00_0000  -->  0 100_1 111_0 000_....
    // case: 32 -> 0x4f80_0000  -->  0 100_1 111_1 000_....
    // case: 1 -> 0x4000_0000  -->  0 010_0 000_0 000_0000....
    // case: 0 -> 0x3f80_0000  -->  0 011_1 111_1 000_0000_.....
    // 기본적인 x + bias 개념 확인
    return (exponent);
}
