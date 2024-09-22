//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
        auto temp = node;
        auto t = temp->next;

        while(t->next != nullptr)
        {
            temp -> val = t->val;
            temp = t, t = t->next;
        }

        temp -> val = t->val;
        //temp = t, t = t->next;
        
        temp->next = nullptr;
        delete t;
    }
};