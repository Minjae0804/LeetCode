
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> a = nums, res;
        std::sort(a.begin(), a.end());

        for (int n : nums) {
            auto it = std::find(a.begin(), a.end(), n);
            int index = it - a.begin();
            res.push_back(index);
        }

        return res;
    }
};