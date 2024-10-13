#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int StrToInt(string x) {
        int ans = 0,t = 0;
        while(x.size() && x.back() != '-') {
            ans += (x.back() - '0') * pow(10, t);
            x.pop_back(), t++;
        }
        if(x.empty())
            return ans;
        return -ans;
    }

    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto &i : tokens) {
            if((i[0] >= '0' && i[0] <= '9') || i.size() > 1)
                st.push(StrToInt(i));
            else {
                int x,y;
                y = st.top(), st.pop(), x = st.top(), st.pop();

                switch (i[0]) {
                    case '+' :
                        st.push(x+y);
                        break;
                    case '-' :
                        st.push(x-y);
                        break;
                    case '*' :
                        st.push(x*y);
                        break;
                    case '/' :
                        st.push((int)(x/y*1.0f));  
                        break;  
                }
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string> ve = {"2","1","+","3","*"};
    Solution slu;
    cout << slu.evalRPN(ve);
}