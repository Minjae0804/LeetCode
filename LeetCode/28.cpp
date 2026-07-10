#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int a;
        return (a = haystack.find(needle) != string::npos ? a : -1);
    }
};