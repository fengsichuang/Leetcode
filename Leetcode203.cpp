//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        while(head != nullptr && head -> val == val)
        {
            auto temp = head;
            head = head->next;
            delete temp;
        }

        if(head == nullptr || head -> next == nullptr)
            return head;

        auto temp = head->next;
        auto last = head;

        while(temp != nullptr)
        {            
            if(temp->val == val)
            {
                last->next = temp->next;            
                delete(temp);
                temp = last->next;
                continue;
            }

            temp = temp->next;
            last = last->next;
        }

        return head;
    }
};