#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
        int removeElement(vector<int>& nums, int val) 
        {
            int space = 0, pos = 0, cnt = 0;//双指针

            for(;pos < nums.size();pos++)
            {
                if(nums[pos] == val)
                    continue;
                
                nums[space] = nums[pos];
                space++, cnt++;
            }

            return cnt;
        }
};

int main()
{
    vector <int> ve = {3,2,2,3};
    Solution slu;
    cout << slu.removeElement(ve,2) << endl;
}