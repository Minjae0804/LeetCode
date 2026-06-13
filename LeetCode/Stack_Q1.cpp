#if 0
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stack;

        for (int i = 1; i <= n; ++i) {
            if (find(target.begin(), target.end(), i) != target.end()) {
                stack.push_back("Push");
            } else {
                if (target.back() < i) break;
                stack.push_back("Push");
                stack.push_back("Pop");
            }
        }

        return stack;
    }
};
#endif