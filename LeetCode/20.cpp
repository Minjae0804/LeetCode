#if 0
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        while (s != "") {
            auto it = find_if(s.begin(), s.end() - 1, [&](char& c) {
                return (
                    (c == '(' && *(&c + 1) == ')') ||
                    (c == '[' && *(&c + 1) == ']') ||
                    (c == '{' && *(&c + 1) == '}')
                );
            });
            if (it != s.end() - 1) 
                s.erase(it, it + 2);
            else 
                return false;
        }
        return true;
    }
};

#endif