/*Man!*/
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        auto temp = head;
        auto tempNext = temp->next;
        auto Next = tempNext->next;
        temp->next = Next, tempNext->next = temp;
        head = tempNext;
        auto front = temp;

        if(temp->next == nullptr || temp->next->next == nullptr)
            return head;
        else
        {
            temp = temp->next;
            tempNext = temp->next;
            Next = tempNext->next;
        }

        while(1)
        {
            temp->next = Next, tempNext->next = temp;
            front->next = tempNext;
            
            if(temp->next == nullptr || temp->next->next == nullptr)
                return head;
            else
            {
                front = temp;
                temp = temp->next;
                tempNext = temp->next;
                Next = tempNext->next;
            }

        }   
    }
};