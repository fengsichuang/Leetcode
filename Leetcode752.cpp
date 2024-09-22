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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        if(head == nullptr)
            return vector<ListNode*>{head};

        auto temp = head;

        vector <ListNode*> ve(k,nullptr);

        int size = 0;
        while(temp != nullptr)
        {
            size++;
            temp = temp->next;
        }

        int avg = size / k;
        int rem = size % k;        
        temp = head;
        ListNode* pre = nullptr;

        for(int i = 0;i < k;i++)
        {
            ve[i] = temp;
            int len = (rem > 0) ? (avg + 1) : avg; 

            for(int j = 0;j < len;j++)
            {
                pre = temp;
                temp = temp->next;
            }

            if(pre != nullptr)
                pre->next = nullptr;
            if(rem > 0)
                rem--;
        }
        
        return ve;
    }
};