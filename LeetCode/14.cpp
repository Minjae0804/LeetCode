#if 0

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (string str : strs) if (str == "") return  "";

        string prefix = strs[0];
        int preLen = strs[0].length();

        for (int i = 0; i < strs.size(); ++i) {
            for (int i = 0; i < strs.size(); ++i) {
                for (int j = 0; j < preLen; ++j)
                    if (prefix[j] != strs[i][j])
                        prefix.erase(prefix.begin() + j, prefix.end());
                preLen = (strs[i].length() < prefix.length() ? strs[i].length() : prefix.length());
            }
        }
        if (!prefix.empty() && prefix.back() == '\0') prefix.pop_back();

        return prefix;
    }
};

#endif