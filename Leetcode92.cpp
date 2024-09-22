//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* newNode = new ListNode(-1);
        newNode->next = head;
        auto node = newNode;

        for (int i = 0; i < left - 1; i++) {
            node = node->next;
        }

        ListNode *current = node -> next, *next;

        for (int i = 0; i < right - left; i++) {
            next = current->next;
            current->next = next->next;
            next->next = node->next;
            node->next = next;
        }

        return newNode->next;

    }
};