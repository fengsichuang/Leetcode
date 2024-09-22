#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            set <int> st; map <int,bool> mp;
            for(auto &i : nums)
            {
                if(st.find(i) != st.end() && !mp[i])
                    mp[i] = true;

                else if(st.find(i) == st.end())
                {
                    mp[i] = false;
                    st.insert(i);
                }
            }
            int pos = 0;
            for(auto &i : st)
            {
                if(mp[i])
                {
                    nums[pos] = nums[pos+1] = i;
                    pos += 2;
                }
                else
                {
                    nums[pos] = i;
                    pos ++;
                }
            }
            return pos;
        }
};

int main()
{
    vector <int> ve = {1,1,1,2,2,3};
    Solution slu;
    cout << slu.removeDuplicates(ve) << '\n';

    for(auto &i : ve)
        cout << i << ' ';
    cout << '\n';
}