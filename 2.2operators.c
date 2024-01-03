#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x = 5 + 5; // + is an operator and 5 and 5 are operands

    // plus and minus (unary operators)
    int y = -x; // unary minus operator
    int z = +x; // unary plus operator

    // arithmetic operators (binary operators)
    int a = 5 + 5; // addition
    int b = 5 - 5; // subtraction

    // multiplication, division, modulus
    int c = 5 * 5; // multiplication
    int d = 5 / 5; // division
    int e = 5 % 5; // modulus

    // increment and decrement
    int f = 5;
    f++; // f = f + 1   // post increment   (first do other operations then increment)
    f--; // f = f - 1   // post decrement   (first do other operations then decrement)
    ++f; // f = f + 1   // pre increment    (first increment then do other operations)

    // assignment operators
    int g = 5;
    g += 5; // g = g + 5
    g -= 5; // g = g - 5
    g *= 5; // g = g * 5
    g /= 5; // g = g / 5
    g %= 5; // g = g % 5

    // comparison operators
    int h = 5;
    int i = 5;
    bool j = h == i; // equal to
    bool k = h != i; // not equal to
    bool l = h > i;  // greater than
    bool m = h < i;  // less than
    bool n = h >= i; // greater than or equal to
    bool o = h <= i; // less than or equal to

    // logical operators
    bool p = true;
    bool q = false;
    bool r = p && q; // and
    bool s = p || q; // or
    bool t = !p;     // not

    // bitwise operators
    int u = 5;      // 00000101
    int v = 6;      // 00000110
    int w = u & v;  // 00000100  // and
    int x = u | v;  // 00000111  // or
    int y = u ^ v;  // 00000011  // xor
    int z = ~u;     // 11111010  // not
    int a = u << 1; // 00001010 // left shift
    int b = u >> 1; // 00000010 // right shift

    // sizeof operator
    int c = sizeof(int);    // 4 bytes
    int d = sizeof(char);   // 1 byte
    int e = sizeof(float);  // 4 bytes
    int f = sizeof(double); // 8 bytes

    // ternary operator
    int g = 5;
    int h = 6;
    int i = g > h ? g : h; // if g > h then i = g else i = h

    return 0;
}