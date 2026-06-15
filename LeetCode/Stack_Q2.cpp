
#include <vector>
#if 0
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> stack;
        int res = 0;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                auto b = stoi(stack.back()); stack.pop_back();
                auto a = stoi(stack.back()); stack.pop_back();
                if      (s == "+")  res = a + b;
                else if (s == "-")  res = a - b;
                else if (s == "*")  res = a * b;
                else if (s == "/")  res = a / b;
                stack.push_back(to_string(res));
            } else {
                stack.push_back(s);
            }
        }
        return stoi(stack.back());
    }
};

#endif