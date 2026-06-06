
#define NULL nullptr

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* turtle = head;
        ListNode* rabbit = head;


        while (rabbit != nullptr) {
            if (rabbit == turtle) return true;
            turtle = turtle->next;
            if (turtle == nullptr) return true;
            rabbit = rabbit->next;
            if (rabbit == nullptr) return false;
            rabbit = rabbit->next;
        }
        return false;
    }
};