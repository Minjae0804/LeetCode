#if 0
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long
            a = 0,
            ap = 0,
            b = 0,
            bp = 0,
            x, y, z;
        int dup, mis;

        for (int i = 1; i <= nums.size(); ++i) {
            a += i;
            ap += (i * i);
        }
        for (int n : nums) {
            b += n;
            bp += (n * n);
        }

        x = b - a;      // D - M
        y = bp - ap;    // D^2 - M^2
        z = y / x;      // D + M

        dup = (x + z) / 2;
        mis = z - dup;

        return{ dup, mis };
    }
};

#endif