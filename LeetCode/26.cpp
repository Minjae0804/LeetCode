#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = -101;

        for (auto it = nums.begin(); it < nums.end(); ) {
            if (*it == prev) {
                it = nums.erase(it);
            }
            else {
                prev = *it;
                ++it;
            }
        }

        return nums.size();
    }
};