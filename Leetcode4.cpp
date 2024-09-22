#include <bits/stdc++.h>

using namespace std;

/*
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        map <int,int> mp;

        for(int i = 0;i < nums1.size();i++)
            mp[nums1[i]]++;
        for(int i = 0;i < nums2.size();i++)
            mp[nums2[i]]++;
        
        vector <int> ve;
        for(auto &i : mp)
            for(int j = 0;j < i.second;j++)
                ve.push_back(i.first);
        
        return ve.size() % 2 == 0 ? (double)(ve[ve.size()/2-1] + ve[ve.size()/2]) / 2.0 : ve[ve.size()/2];
    }
};
*/

class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) 
    {
        int m = nums1.size(), n = nums2.size();
        int offset1 = 0, offset2 = 0;

        while(1)
        {
            if(offset1 == m)
                return nums2[offset2 + k - 1];
            if(offset2 == n)
                return nums1[offset1 + k - 1];
            if(k == 1)
                return min(nums1[offset1], nums2[offset2]);

            int newOff1 = min(offset1 + k / 2 - 1, m - 1);
            int newOff2 = min(offset2 + k / 2 - 1, n - 1);

            if(nums1[newOff1] <= nums2[newOff2])
            {
                k = k - newOff1 + offset1 - 1;
                offset1 = newOff1 + 1;
            }
            else
            {
                k = k - newOff2 + offset2 - 1;
                offset2 = newOff2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};

int main()
{
    vector <int> a = {1,2}, b = {3,4};
    Solution slu;
    cout << slu.findMedianSortedArrays(a,b);
}