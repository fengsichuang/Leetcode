//Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(ListNode* a, ListNode* b)
{
    return a->val < b->val;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        auto temp = head;
        vector <ListNode*> ve;

        while(temp != nullptr)
        {
            ve.push_back(temp);
            temp = temp->next;
        }

        sort(ve.begin(),ve.end(),cmp);

        head = ve[0];
        ve[ve.size()-1]->next = nullptr;

        for(int i = 0;i < ve.size()-1;i++)
            ve[i]->next = ve[i+1]; 
        
        return head;
    }
};