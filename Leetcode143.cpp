//Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
#include <vector>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return ;
        
        vector <ListNode*> ve;
        auto temp = head;   

        while(temp != nullptr)
        {
            ve.push_back(temp);
            temp = temp->next;
        }

        int len = ve.size();

        int i = 0, j = len-1;

        while(i < j)
        {
            ve[i]->next = ve[j];
            i++;

            if(i == j)
                break;;
            
            ve[j]->next = ve[i];
            j--;
        }

        ve[i]->next = nullptr;
        return;
    }
};