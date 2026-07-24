#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* it1 = head;
        ListNode* it2 = head;

        for (int i = 1; i <= n; ++i) { it1 = it1->next; }
        if (it1 == nullptr) return head->next;

        while (it1->next != nullptr) {
            it1 = it1->next;
            it2 = it2->next;
        }

        it2->next = it2->next->next;

        return head;
    }
};