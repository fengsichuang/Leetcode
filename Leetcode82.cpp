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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        
        map<int,int> mp;
        vector <ListNode*> ve,ans;
        auto temp = head;

        while(temp != nullptr)
        {
            mp[temp->val]++;
            ve.push_back(temp);
            temp = temp->next;
        }

        for(int i = 0;i < ve.size();i++)
        {
            if(mp[ve[i]->val] >= 2)
            {
                continue;
            }

            ans.push_back(ve[i]);
        }
        
        if(ans.size() < 1)
            return nullptr;

        for(int i = 0;i < ans.size()-1;i++)
        {
            ans[i]->next = ans[i+1];
        }


        head = ans.front();
        ans.back()->next = nullptr;

        return head;
    }
};