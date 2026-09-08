#include <stdio.h>

unsigned floatScale2(unsigned uf);

int floatFloat2Int(unsigned uf);

unsigned floatPower2(int x);

int isLessOrEqual(int x, int y);

int main()
{
    // printf("%b, %d\n", (unsigned char)-1, (unsigned char)-1);
    // printf("%b, %d\n", (char)-1, (char)-1);
    // printf("%b, %d\n", (char)1, (char)1);
    // floatScale2(0);
    // floatScale2(0x7FC00000);
    // floatScale2(1);
    // floatScale2(0x80000000);
    // floatScale2(0x800000);
    // floatScale2(0x1);
    // floatScale2(0x7f800000);

    // floatFloat2Int(0x80000000);
    // floatFloat2Int(0x7fffff);

    // floatPower2(31);
isLessOrEqual(-1, -1);
    return 0;
}
// 0111_1111_1100_0000
// 0111_1111_1100_0000
// 1000_0000_...
// 0x7FC00000

#if 0
int main()
{
    // conditional(0x80000000, 4, 5);
    // printf("%d\n", conditional(2, 4, 5));
    // printf("%#034b\n", x + (~max + 0));

    // int x = (((1 << 30) + (~1 + 1)) << 2) + 3;
    // printf("%#034b\n", x);
    // int x = 0;
    // printf("%#034b\n", ~x);
// 0[0x0],-2147483648[0x80000000],-2147483648[0x80000000]
    // -2147483648[0x80000000],-2147483648[0x80000000],-2147483648[0x80000000]
    // 0[0x0],-2147483648[0x80000000],2147483647[0x7fffffff]
    // printf("nbr: %#034b\n", 0x80000000);
    // printf("nbr: %#034b\n", 0x7fffffff);
    //
    // printf("\n%#034b\n", conditional(0x0, 0x80000000, 0x7fffffff));
    // printf("\n%#034b\n", conditional(0x80000000, 0x80000000, 0x7fffffff));
    // printf("%d\n", conditional(0x80000000, 0x80000000, 0x80000000));

    // printf("%#034b, %d\n", (int)0x80000000, (int)0x80000000);
    // printf("%#034b, %d\n", (int)0x80000000 >> 1, (int)0x80000000 >> 1);
    // printf("%#034b, %d\n", (int)0x40000000, (int)0x40000000);
    // printf("%#034b, %d\n", (int)0x40000000 >> 1, (int)0x40000000 >> 1);

    // int x = -122131411;
 // *  Examples: howManyBits(12) = 5
 // *            howManyBits(298) = 10
 // *            howManyBits(-5) = 4
 // *            howManyBits(0)  = 1
 // *            howManyBits(-1) = 1
 // *            howManyBits(0x80000000) = 32
    // int x = 12;
    // int x = 298;
    // int x = -5;
    // int x = 0;
    // int x = -1;
    // int x = 0x80000000;
    // int x = 1 << 31;

    // int a = 1 << 16;
    // int b = 1 << 8;
    // int c = 1 << 4;
    // int d = 1 << 2;
    // int e = 1 << 1;
    //
    // int is_negative = (x >> 31) & 1;
    // int _x = (~(!is_negative) + 1) & x | (~is_negative + 1) & ~x; // 최상위 비트란 양수인 경우 1을 찾아주고, 음수인 경우 0을 찾아주면 된다.
    // printf("%#034b, %d\n", _x, _x);
    //
    // int result = 0;
    //
    // int is_less_then_a = ((_x + (~a + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    // _x = _x >> (16 & (~(!is_less_then_a) + 1));
    // result = result + (16 & (~(!is_less_then_a) + 1));
    // printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_a, result);
    //
    // int is_less_then_b = ((_x + (~b + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    // _x = _x >> (8 & (~(!is_less_then_b) + 1));
    // result = result + (8 & (~(!is_less_then_b) + 1));
    // printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_b, result);
    //
    // int is_less_then_c = ((_x + (~c + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    // _x = _x >> (4 & (~(!is_less_then_c) + 1));
    // result = result + (4 & (~(!is_less_then_c) + 1));
    // printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_c, result);
    //
    // int is_less_then_d = ((_x + (~d + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    // _x = _x >> (2 & (~(!is_less_then_d) + 1));
    // result = result + (2 & (~(!is_less_then_d) + 1));
    // printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_d, result);
    //
    // int is_less_then_e = ((_x + (~e + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    // _x = _x >> (1 & (~(!is_less_then_e) + 1));
    // result = result + (1 & (~(!is_less_then_e) + 1));
    // printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_e, result);
    // result = (~(!!result) + 1) & (result + 1 + 1) | (~(!result) + 1) & 1;// 양수든 음수든 부호 비트 하나는 필요하고, 아래 방식이면 자리수가 1비트 만큼 덜 표현된다.
    // return (result);


 // *  Examples: howManyBits(12) = 5
 // *            howManyBits(298) = 10
 // *            howManyBits(-5) = 4
 // *            howManyBits(0)  = 1
 // *            howManyBits(-1) = 1
 // *            howManyBits(0x80000000) = 32
    // int x = 12;
    // int x = 298;
    // int x = -5;
    // int x = 0;
    // int x = -1;
    // int x = 0x80000000;
    int x = 1;
    // int x = 0b01000000000000000000000000000000; // 30이 나오는게 맞지
    // int x = 1 << 31;



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
    printf("%#034b, %d\n", x, x);
    printf("%#034b, %d\n", _x, _x);

    int result = 0;

    is_less_then_a = ((_x + (~a + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_a = ((!is_less_then_a << 31) >> 31);
    _x = _x >> (16 & mask_a);
    result = result + (16 & mask_a);
    printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_a, result);

    is_less_then_b = ((_x + (~b + 1)) >> 31) & 1;
    mask_b = ((!is_less_then_b << 31) >> 31);
    _x = _x >> (8 & mask_b);
    result = result + (8 & mask_b);
    printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_b, result);

    is_less_then_c = ((_x + (~c + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_c = ((!is_less_then_c << 31) >> 31);
    _x = _x >> (4 & mask_c);
    result = result + (4 & mask_c);
    printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_c, result);

    is_less_then_d = ((_x + (~d + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_d = ((!is_less_then_d << 31) >> 31);
    _x = _x >> (2 & mask_d);
    result = result + (2 & mask_d);
    printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_d, result);

    is_less_then_e = ((_x + (~e + 1)) >> 31) & 1; // -> 1이라고? 음수가 나왔어? _x보다 a가 더 크다. shift필요 없다.
    mask_e = ((!is_less_then_e << 31) >> 31);
    _x = _x >> (1 & mask_e);
    result = result + (1 & mask_e);
    printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_e, result);
    // result = (((!!result << 31) >> 31) & (result + 1 + 1)) | (((!result << 31) >> 31) & 1);// 양수든 음수든 부호 비트 하나는 필요하고, 아래 방식이면 자리수가 1비트 만큼 덜 표현된다.
    // 마지막 남은게 1인지 0인지 확인해서 살려준다.
    result = 1 + (((!!result << 31) >> 31) & (result)) + _x; // 부호 비트 + 누적 result + _x(1 or 0)
    printf("%#034b, %d, %d, %d\n", _x, _x, is_less_then_e, result);
    printf("mask_a: %d\n\
            mask_b: %d\n\
            mask_c: %d\n\
            mask_d: %d\n\
            mask_e: %d\n", mask_a, mask_b, mask_c, mask_d, mask_e);
    return (result);
}

int isTmax(int x)
{
    int two_complement = ~(x + 1) + 1;
    int msb_only = ((x & two_complement) >> 31) & 1;
    return (msb_only);
}


int main()
{
    int a = 1 << 31;

    printf("%d\n", a);
    printf("%#034b\n", a);
    printf("%#034b\n", ~a + 1);
    printf("%#034b\n", a + (~a + 1));
    printf("\n");

    int k = 1 << 31;
    printf("%d\n", isTmax(k));

    printf("%#034b\n", 1);
    printf("%#034b\n", ~1);
    printf("%#034b\n", !1);
    printf("%#034b\n", !10);
    printf("\n");
    printf("%#034b\n", 0);
    printf("%#034b\n", ~0);
    printf("%#034b\n", !0);

    return (0);
}


ERROR: Test bitXor(-2147483648[0x80000000],2147483647[0x7fffffff]) failed...

-2147483648
2147483647

getconf INT_MAX
2147483647
getconf INT_MIN
-2147483648

#endif
