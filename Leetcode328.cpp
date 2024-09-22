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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        int cnt = 0;
        auto temp = head;
        auto second = head->next;

        if(second == nullptr)
            return head;

        while(true)
        {
            
            cnt++;
            auto tempNext = temp->next;            
            
            if(tempNext == nullptr)
            {
                if(cnt % 2 != 0)
                {
                    
                    temp->next = second;
                    return head;
                }
            }

            if(tempNext->next == nullptr)
            {
                if((cnt+1) % 2 == 0)
                {
                    temp->next = second;
                    return head;
                }
            }


            temp->next = tempNext->next;
            temp = tempNext;
        }
        
    }
}; 