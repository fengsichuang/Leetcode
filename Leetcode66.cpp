#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int pos = digits.size();

        vector <int> ve(101);

        for(int i = 0;i < digits.size();i++)
            ve[i+1] = digits[i];
        
        ve[pos]++;
        while(ve[pos] == 10)
        {
            ve[pos] = 0;
            ve[pos-1]++;
            pos--;
        }
        
        vector <int> ans;
        if(ve[0] == 0)
        {
            for(int i = 1;i <= digits.size();i++)
                ans.push_back(ve[i]);
        }
        else
        {
            for(int i = 0;i <= digits.size();i++)
                ans.push_back(ve[i]);
        }

        return ans;
    }
};

int main()
{
    vector <int> nums = {1,0,0,9};
    Solution slu;
    vector <int> temp = slu.plusOne(nums);

    for(auto &i : temp)
        cout << i << ' ';
    cout << endl;
}