#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int cnt = 0;
        string::iterator it;

        for(it = s.begin();*it != '\0';it++)
        {
            if(*it == '(')
                cnt++;
            
            else if(*it == ')')
            {
                if(cnt == 0)
                {
                    s.erase(it);
                    it--;
                }

                else
                    cnt--;
            }
        }
        
        if(cnt == 0)
            return s;

        cnt = 0;

        for(it = s.end();it != s.begin();it--)
        {
            if(*it == ')')
                cnt++;
            
            else if(*it == '(')
            {
                if(cnt == 0)
                {
                    s.erase(it);
                }
                    
                else
                    cnt--;
            }
        }

        if(*it == ')')
            cnt++;
            
        else if(*it == '(')
        {
            if(cnt == 0)
            {
                s.erase(it);
            }
                    
            else
                cnt--;
        }

        return s;
    }
};

int main()
{
    Solution slu;
    string s = "))((";
    cout << slu.minRemoveToMakeValid(s);
}