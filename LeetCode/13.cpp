#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int getValue(char c) {
        switch (c) {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
    }

public:
    int romanToInt(std::string s) {

        reverse(s.begin(), s.end());
        int sum = 0, prevVal = 0;

        for (int i = 0; i < s.length(); ++i) {
            int currVal = getValue(s[i]);

            if (currVal < prevVal) {
                sum -= currVal;
            } else 
                sum += currVal;

            prevVal = currVal;
        }

        return sum;
    };
};
