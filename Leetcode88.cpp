#include <bits/stdc++.h>

using namespace std;

/*还是STL高手*/
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        map <int,int> mp;

        for(int i = 0;i < m;i++)
            mp[nums1[i]]++;
        for(int i = 0;i < n;i++)
            mp[nums2[i]]++;
        
        int pos = 0;
        for(auto &i : mp)
        {
            for(int j = 0;j < i.second;j++)
            {
                nums1[pos] = i.first;
                pos++;
            }
        }
    }
};

int main()
{
    vector <int> a = {1,2,3,0,0,0}, b = {2,5,6};
    Solution slu;
    slu.merge(a,3,b,3);

    for(auto &i : a)
        cout << i << ' ';
}