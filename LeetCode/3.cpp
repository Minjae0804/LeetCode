#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<char> arr;

        for (char ch : s) {
            auto chIt = find(arr.begin(), arr.end(), ch);

            if (chIt != arr.end()) arr.erase(arr.begin(), chIt + 1);

            arr.push_back(ch);
            ans = arr.size() > ans ? arr.size() : ans;
        }

        return ans;
    }
};

#endif