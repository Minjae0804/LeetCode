#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int char_map[128] = { 0 };

        int left = 0;
        int ans = 0; 

        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];

            if (char_map[current_char] > left) left = char_map[current_char];
            char_map[current_char] = right + 1;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

    //int lengthOfLongestSubstring(string s) {
    //    int ans = 0;
    //    vector<char> arr;

    //    for (char ch : s) {
    //        auto chIt = find(arr.begin(), arr.end(), ch);

    //        if (chIt != arr.end()) arr.erase(arr.begin(), chIt + 1);

    //        arr.push_back(ch);
    //        ans = arr.size() > ans ? arr.size() : ans;
    //    }

    //    return ans;
    //}
};

#endif