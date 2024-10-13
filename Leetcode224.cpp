#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

class Solution {
public:
    vector <string> ve;
    stack <char> op;

    ll StrToInt(string x) {
        ll ans = 0,t = 0;
        while(x.size() && x.back() != '-') {
            ans += (x.back() - '0') * pow(10, t);
            x.pop_back(), t++;
        }
        if(x.empty())
            return ans;
        return -ans;
    }

    ll evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto &i : tokens) {
            if((i[0] >= '0' && i[0] <= '9') || i.size() > 1)
                st.push(StrToInt(i));
            else {
                ll x,y;
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

    ll calculate(string s) {
        for(int i = 0;i < s.size();i++) {
            if(s[i] == ' ') {
                s.erase(i,1);
                i--;
            }

            else if(s[i] == '-' && (i == 0 || s[i-1] == '(')) {
                s.insert(i,1,'0');
                ve.push_back(string(1,'0'));
            }

            else if(s[i] == '+' || s[i] == '-') {
                while (op.size() && op.top() != '(') {
                    ve.push_back(string(1,op.top()));
                    op.pop();
                }
                op.push(s[i]);
            }

            else if(s[i] == '(')
                op.push(s[i]);
            
            else if(s[i] == ')') {
                while (op.size() && op.top() != '(') {
                    ve.push_back(string(1,op.top()));
                    op.pop();
                }
                op.pop();
            }

            else if(s[i] >= '0' && s[i] <= '9') {
                int j = i; string n;
                while(s[j] >= '0' && s[j] <= '9') {
                    n = n + s[j], j++;
                }
                ve.push_back(n), i = j-1;
            }
        }

        while(!op.empty()) {
            ve.push_back(string(1,op.top()));
            op.pop();
        }

        return evalRPN(ve);
    }
};

int main()
{
    Solution slu;
    string str = "143525354325423";
    cout << slu.calculate(str);
}