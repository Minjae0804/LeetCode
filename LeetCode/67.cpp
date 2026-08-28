#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string& longstr = (a.size() > b.size() ? a : b);
        string& shortstr = (a.size() > b.size() ? b : a);
        shortstr.insert(shortstr.begin(), longstr.size() - shortstr.size(), '0');

        std::vector<int> carryArr;
        for (int i = longstr.size() - 1; i >= 0; --i) {
            if (longstr[i] != shortstr[i]) { longstr[i] = '1'; }
            else { if (longstr[i] == '1') { longstr[i] = '0'; carryArr.push_back(i); } }
        }

        for (int i : carryArr) carry(longstr, i);

        return longstr;
    }

    void carry(string& s, int i) {
        if (i == 0) { s.insert(s.begin(), '1'); return; }

        if (s[i - 1] == '1') { s[i - 1] = '0'; carry(s, i - 1); }
        else { s[i - 1] = '1'; return; }
    };


    int main() {
        Solution s;
        std::cout << s.addBinary("1111", "1111100101") << std::endl;
    }