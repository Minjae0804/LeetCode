#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto it = digits.end() - 1; it >= digits.begin(); --it) 
            if (*it == 9)   { *it = 0; } 
            else            { *it += 1; return digits; }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};