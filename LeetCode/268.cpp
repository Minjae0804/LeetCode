#if 0
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xsum = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            xsum ^= i;
            xsum ^= nums[i];
        }

        return xsum;
    }
};

#endif