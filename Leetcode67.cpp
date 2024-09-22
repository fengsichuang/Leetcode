#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
        string addBinary(string a, string b) 
        {
            int maxL = max(a.size(),b.size());

            //使a与b的位数相同
            while(a.size() < maxL)
                a = '0' + a;
            
            while(b.size() < maxL)
                b = '0' + b;

            string ans = a;
            bool addlength = false;

            for(int i = ans.size()-1;i > 0;i--)
            {
                ans[i] = ans[i] - '0' + b[i];

                if(ans[i] - '0' >= 2)
                {
                    ans[i-1]++;
                    ans[i] -= 2;
                }
            }

            ans[0] = ans[0] - '0' + b[0];

            if(ans[0] - '0' >= 2)
            {
                ans[0] -= 2;
                ans = '1' + ans;
            }

            return ans;
        }
};

int main()
{
    string a = "1010", b = "1010";
    Solution slu;
    cout << slu.addBinary(a,b) << '\n';
}