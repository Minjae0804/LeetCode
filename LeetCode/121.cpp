#if 0
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int benefit = 0, min = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min) min = prices[i];
            if (prices[i] > min) benefit = (prices[i] - min) > benefit ? (prices[i] - min) : benefit;
        }
        return benefit;
    }
};

#endif