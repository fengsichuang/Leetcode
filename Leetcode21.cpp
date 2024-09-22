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

ListNode* select(ListNode* l1,ListNode* l2)
{
    if(l1 && l2)
    {
        return l1->val < l2->val ? l1 : l2;
    }
    else if(l1)
        return l1;
    else if(l2)
        return l2;
    else
        return nullptr;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* ori = new ListNode(0,nullptr);
        auto temp = ori;

        while(select(list1,list2))
        {
            auto t = select(list1,list2);
            temp->next = t, temp = temp->next;

            if(t == list1)
                list1 = list1->next;
            else
                list2 = list2->next;
        }
        return ori->next;
    }
};