#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        int a[35],num = x;

        bool neg = (num < 0 ? true : false);

        num = abs(num);

        int i = 0;

        while(num > 0)
        {
            a[i] = num % 10;
            i++, num /= 10;
        }

        i--;

        long temp = 1, ans = 0;
        for(int j = 0;j <= i;j++)
        {            
            long check = ans + a[i-j] * temp;
            if(check > 2147483648)
                return 0;

            ans += (a[i-j] * temp);

            temp *= 10;
        }

        if(!neg)
            return ans;
        else
            return -1 * ans;
    }
};

int main()
{
    Solution t;
    int x;  cin >> x;
    cout << t.reverse(x);
}