#include <bits/stdc++.h>

using namespace std;

/*
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int space = 0, pos = 1, cnt = 1;
        
        for(;pos < nums.size();pos++)
        {
            if(nums[pos] == nums[space])
                continue;

            space++, nums[space] = nums[pos];
            cnt++;
        }

        return cnt;
    }
};
*/

/*我们先进的双指针已经完全超越了老实的集合*/

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        set <int> st;

        for(auto &i : nums)
        {
            st.insert(i);
        }

        int pos = 0;
        for(auto &i : st)
        {
            nums[pos] = i;
            pos++;
        }

        return st.size();
    }
};

int main()
{
    vector <int> ve = {0,0,1,1,1,2,2,3,3,4};
    Solution slu;
    cout << slu.removeDuplicates(ve) << '\n';
    
    for(auto &i : ve)
        cout << i << ' ';
    cout << endl;
}