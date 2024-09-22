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
    ListNode* middleNode(ListNode* head) {
        auto temp = head;
        if(head == nullptr || head->next == nullptr)
            return head;
        
        int cnt = 0;

        while(temp->next != nullptr)
        {
            temp = temp->next;
            cnt++;
        }

        temp = head;

        for(int i = 0;i < cnt/2;i++)
        {
            temp = temp->next;
        }

        if(cnt%2 == 1)
            return temp->next;

        return temp;
    }
};