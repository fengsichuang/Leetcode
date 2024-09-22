//Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;

        vector <ListNode*> ve;

        auto temp = head;

        while(temp != nullptr)
        {
            ve.push_back(temp);
            temp = temp->next;
        }

        for(int i = 0;i <= ve.size();i += k)
        {
            if(i+k > ve.size())
                break;
            reverse(ve.begin() + i,ve.begin() + i + k);
        }

        head = ve.front();

        for(int i = 0;i < ve.size()-1;i++)
            ve[i]->next = ve[i+1];

        ve.back()->next = nullptr;

        return head;
    }
};