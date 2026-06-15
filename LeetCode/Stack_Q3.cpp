
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0), stack;
        int prev_time = 0;

        for (string log : logs) {
            int c1 = log.find(':');
            int c2 = log.find(':', c1 + 1);

            int id = stoi(log.substr(0, c1));
            string type = log.substr(c1 + 1, c2 - c1 - 1);
            int timestamp = stoi(log.substr(c2 + 1));

            if (type == "start") {
                if (!stack.empty()) { res[stack.back()] += (timestamp - prev_time); }
                stack.push_back(id);
                prev_time = timestamp;
            } else if (type == "end") {
                res[stack.back()] += (timestamp - prev_time + 1);
                stack.pop_back();
                prev_time = timestamp + 1;
            }
        }

        return res;
    }
};