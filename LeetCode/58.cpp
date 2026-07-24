#if 0
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int spaceRemovedSLen = s.size() - 1;
        int frontspace = 0;
        bool breakflag = false;

        for (int i = s.size() - 1; i != -1; --i) {
            if (s[i] != ' ') break;
            --spaceRemovedSLen;
            ++frontspace;
        }

        for (int i = spaceRemovedSLen; i != -1; --i) {
            if (s[i] == ' ') {
                breakflag = true;
                break;
            }
            len++;
        }

        return breakflag ? len : s.size() - frontspace;
    }
};

#endif