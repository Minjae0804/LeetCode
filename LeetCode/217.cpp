#if 0
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() != unordered_set<int>(nums.begin(), nums.end()).size();
    }
};

#endif