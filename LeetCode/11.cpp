#include <vector>

using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {
        int maxWater = 0;
        vector<int>::iterator left(height.begin()), right(height.end() - 1);
        
        while (left < right) {
            int width = right - left;
            long long current_height = min(*left, *right);
            long long current_water = width * current_height;

            maxWater = current_water > maxWater ? current_water : maxWater;

            switch (*left < *right) {
            case true:
                right--;
                break;
            case false: 
                left++;
                break;
            }
        }

        return maxWater;
    }
};