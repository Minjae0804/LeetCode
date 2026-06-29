#include <string>

using namespace std;

class Solution {
public:
    bool isPalindromeRange(string::iterator left, string::iterator right) {
        if (left >= right) return true;
        if (*left != *right) return false;

        return isPalindromeRange(left + 1, right - 1);
    }

    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        string::iterator start_it = s.begin();
        int max_len = 1;

        for (auto left = s.begin(); left < s.end(); ++left) {
            for (auto right = s.end() - 1; right > left; --right) {
                if (right - left + 1 <= max_len) break;
                if (*left == *right && isPalindromeRange(left, right)) {
                    max_len = right - left + 1;
                    start_it = left;
                    break;
                }
            }
        }

        return s.substr(distance(s.begin(), start_it), max_len);
    }
};