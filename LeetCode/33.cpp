#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left = nums.begin();
        auto right = nums.end() - 1;

        while (left < right) {
            auto mid = left + (right - left) / 2; 
            
            if (*mid == target) return std::distance(nums.begin(), mid);
            
            if (*left <= *mid) {
                if (*left <= target && target < *mid) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (*mid < target && target <= *right) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};