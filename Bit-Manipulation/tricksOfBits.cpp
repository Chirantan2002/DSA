#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 16, y = -5, num = 29; // 29 = 11101 in binary

    // 1. Check if a number is a power of two
    cout << "1. isPowerOfTwo(" << x << "): " 
         << (x > 0 && (x & (x - 1)) == 0) << "\n";

    // 2. Count set bits
    int n = num;
    int count = 0;
    while (n) { n &= (n - 1); count++; }
    cout << "2. countSetBits(" << num << "): " << count << "\n";

    // 3. Isolate lowest set bit
    cout << "3. lowestSetBit of " << num << ": " << (num & -num) << "\n";

    // 4. Turn off the lowest set bit
    cout << "4. num with lowest set bit off: " << (num & (num - 1)) << "\n";

    // 5. Check if two numbers have opposite signs
    cout << "5. oppositeSigns(" << x << "," << y << "): " << ((x ^ y) < 0) << "\n";

    // 6. Swap two numbers without a temp variable
    int a = 3, b = 7;
    a ^= b; b ^= a; a ^= b;
    cout << "6. swapped: a=" << a << " b=" << b << "\n";

    // 7. Get the ith bit (i=3)
    int i = 3;
    cout << "7. bit " << i << " of " << num << ": " << ((num >> i) & 1) << "\n";

    // 8. Set the ith bit (i=1)
    cout << "8. set bit " << i << " in " << num << ": " << (num | (1 << i)) << "\n";

    // 9. Clear the ith bit (i=2)
    cout << "9. clear bit 2 in " << num << ": " << (num & ~(1 << 2)) << "\n";

    // 10. Toggle the ith bit (i=0)
    cout << "10. toggle bit 0 in " << num << ": " << (num ^ (1 << 0)) << "\n";

    // 11. Count trailing zeros
    cout << "11. trailing zeros in " << x << ": " << __builtin_ctz(x) << "\n";

    // 12. Generate subsets for n=3
    cout << "12. subsets of {0,1,2}:\n";
    int sz = 3;
    for (int mask = 0; mask < (1 << sz); mask++) {
        cout << "{ ";
        for (int j = 0; j < sz; j++)
            if (mask & (1 << j)) cout << j << " ";
        cout << "}\n";
    }

    // 13. Check if subset
    int A = 0b101, B = 0b111;
    cout << "13. Is A subset of B? " << ((A & B) == A) << "\n";

    // 14. Gray code generation for first 8 numbers
    cout << "14. Gray code for 0..7: ";
    for (int k = 0; k < 8; k++)
        cout << (k ^ (k >> 1)) << " ";
    cout << "\n";
}
