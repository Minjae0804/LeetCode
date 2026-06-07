#if 0
#include <stdint.h>

class Solution {
public:
    int reverseBits(int n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};

#endif