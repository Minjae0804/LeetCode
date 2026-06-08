#if 0
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (int i : nums) {
            if (i == 0) {
                maxCount = (count >= maxCount ? count : maxCount);
                count = 0;
            }
            else ++count;
        }
        maxCount = (count >= maxCount ? count : maxCount);

        return maxCount;
    }
};

#endif