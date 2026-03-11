class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;  // special case

        int numBits = 0;
        int temp = n;

        // Count the number of bits in n
        while (temp > 0) {
            numBits++;
            temp = temp >> 1;
        }

        int mask = (1 << numBits) - 1;  // all 1s in the bit length of n
        return n ^ mask;                // XOR flips the bits
    }
};