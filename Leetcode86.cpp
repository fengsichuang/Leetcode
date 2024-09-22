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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        auto temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        auto last = temp;
        auto tailNode = last;

        while(head->val >= x && head != last)
        {
            tailNode->next = head;
            head = head->next;
            tailNode = tailNode->next;
            tailNode->next = nullptr;
        }

        if(head->val >= x)
        {
            tailNode->next = head;
            head = head->next;
            tailNode = tailNode->next;
            tailNode->next = nullptr;
        }

        if(head == last)
            return head;

        temp = head;

        auto tempFront = temp;
        temp = temp->next;

        while(1)
        {
            if(temp == last)
            {
                if(temp->val >= x && tailNode != last)
                {
                    tempFront->next = temp->next;
                    tailNode->next = temp;
                    tailNode = tailNode->next;
                    tailNode->next = nullptr;
                    temp = tempFront->next;
                }
                    
                return head;
            }

            if(temp->val >= x)
            {
                tempFront->next = temp->next;
                tailNode->next = temp;
                tailNode = tailNode->next;
                tailNode->next = nullptr;
                temp = tempFront->next;
            }
            else
            {
                tempFront = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};