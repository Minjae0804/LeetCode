#if 0

#include <iostream>
using namespace std;

class Solution {
public:
    int memo[46];
    int climbStairs(int n) {
        if (n <= 2) return n;
        if (memo[n] != 0) return memo[n];
        return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

#endif