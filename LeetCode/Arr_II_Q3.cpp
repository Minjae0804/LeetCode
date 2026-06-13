#if 0
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> appeared(n + 1, false);
        vector<int> res;    

        for (int num : nums) 
            appeared[num] = true;

        for (int i = 1; i <= n; ++i) 
            if (!appeared[i]) 
                res.push_back(i);

        return res;
    }
};

#endif