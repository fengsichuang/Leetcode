#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> sbgcc;
        map <int,int> mp;

        for(int i = 0;i < nums.size();i++)
        {
            if(mp[nums[i]] != 0)
            {
                if(target % 2 == 0 && target / 2 == nums[i])
                {
                    sbgcc.push_back(mp[nums[i]]-1);
                    sbgcc.push_back(i);
                    return sbgcc;
                }
            }
            
            mp[nums[i]] = i+1;
        }

        for(auto &i : mp)
        {
            int temp = i.first;
            if(mp[target - temp] != 0)
            {
                sbgcc.push_back(i.second-1);
                sbgcc.push_back(mp[target - temp]-1);
                return sbgcc;
            }
        }

        return sbgcc;
    }
};

int main()
{
    int n,tar;
    Solution solution;
    vector <int> nums;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int t;  cin >> t;
        nums.push_back(t);
    }

    cin >> tar;

    auto temp = solution.twoSum(nums,tar);

    for(auto &i : temp)
        cout << i << ' ';
    cout << endl;
}