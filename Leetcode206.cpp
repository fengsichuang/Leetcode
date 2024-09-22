//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
            
        ListNode *l1 = nullptr, *l2 = head;

        while(l2->next != nullptr)
        {
            ListNode *l3 = l2 -> next;
            l2->next = l1;
            l1 = l2;
            l2 = l3;
        }
    }
};