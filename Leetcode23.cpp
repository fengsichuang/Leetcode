#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool cmp(ListNode* l1,ListNode* l2)
{
    return l1->val < l2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {

        vector<ListNode*> ve;
        for(ListNode* &i : lists)
        {
            auto temp = i;

            while(temp != nullptr)
            {
                ve.push_back(temp);
                temp = temp->next;
            }
        }

        if(ve.size() < 1)
            return nullptr;
        
        sort(ve.begin(),ve.end(),cmp);

        for(int i = 0;i < ve.size()-1;i++)
            ve[i]->next = ve[i+1];

        ve.back()->next = nullptr;
        return ve.front();
    }
};