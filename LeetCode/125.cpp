#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "", temp2 = "";

        for (char ch : s) {
            if (!isalnum(ch)) continue;
            temp.push_back(tolower(ch));
        }

        temp2 = temp; 
        reverse(temp2.begin(), temp2.end());
        if (temp == temp2) return true;
        else return false;
    }

    bool isPalindromeAnother(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else {
                if (tolower(s[left]) != tolower(s[right])) return false;
                ++left;
                --right;
            }
        }
        return true;
    }
};