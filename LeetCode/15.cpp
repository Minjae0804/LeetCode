#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::vector<int> prev;
        sort(nums.begin(), nums.end());

        for (auto it = nums.begin(); it < nums.end(); ++it) {
            if (it > nums.begin() && *it == *(it - 1)) continue;

            auto left = it + 1;
            auto right = nums.end() - 1;

            if (left == nums.end()) break;

            while (left < right) {
                int sum = *it + *left + *right;

                if (sum < 0)   ++left;
                else if (sum > 0)   --right;
                else if (sum == 0) {
                    std::vector<int> target = { *it, *left, *right };
                    ans.push_back(target);
                    ++left; --right;
                    prev = target;
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};