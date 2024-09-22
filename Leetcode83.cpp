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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == nullptr)
            return head;

        auto temp = head;
        ListNode* pre = nullptr;

        set<int> st;

        while(temp != nullptr)
        {
            if(st.find(temp->val) != st.end())
            {
                pre->next = temp->next;
                temp = temp->next;
            }

            else
            {
                st.insert(temp->val);
                pre = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};