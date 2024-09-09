#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        vector <int> ve;

        ve.push_back(0);

        for(int i = 0;i < arr.size();i++)
            ve.push_back(ve.back() + arr[i]);
        
        int ans = 0, len = 3, n = arr.size();

        ans += ve.back();

        while(len <= n)
        {
            for(int i = len;i <= n;i++)
            {
                ans += (ve[i] - ve[i-len]);
            }
            len += 2;
        }
        return ans;
    }
};

int main()
{
    vector <int> nums = {10,11,12};
    Solution slu;
    int t = slu.sumOddLengthSubarrays(nums);
    cout << t << endl;
}