#if 0
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string a = std::to_string(x);
        std::string b = a;
        reverse(b.begin(), b.end());;
        return a == b;
    }
};

#endif