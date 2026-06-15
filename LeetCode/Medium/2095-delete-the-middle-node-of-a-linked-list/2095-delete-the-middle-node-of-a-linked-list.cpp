/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* cur = head;
        int listSize = 0;
        while (cur != nullptr) {
            cur = cur->next;
            listSize++;
        }

        if (listSize == 1) {
            return nullptr;
        }

        int targetIndex = listSize / 2;
        listSize = 0, cur = head;
        while (listSize + 1 < targetIndex) {
            cur = cur->next;
            listSize++;
        }
        cur->next = cur->next->next;
        return head;
    }
};