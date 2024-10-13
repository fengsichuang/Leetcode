#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
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
    
    ll evalRPN(vector <string> &tokens) {
        stack <ll> st;
        for(auto &i : tokens) {
            if((i[0] >= '0' && i[0] <= '9') || i.size() > 1)
                st.push(StrToInt(i));
            else if(!st.empty()){
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
                        st.push((ll)(x/y*1.0f));  
                        break;  
                }
            }
        }
        return st.top();
    }

public:
    ll calculate(string s) {
        map<char,ll> mp;
        stack<string> num; stack<char> t; vector<string> ve;
        bool neg = false;
        mp['+'] = 0, mp['-'] = 0, mp['*'] = 1, mp['/'] = 1;

        for(int i = 0;i < s.size();i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int j = i; string n;
                while(j < s.size() && (s[j] >= '0' && s[j] <= '9')) {
                    n += s[j], j++;
                }
                if(neg) {
                    neg = false;
                    n = '-' + n;
                }
                ve.push_back(n);
                i = j-1;
            }

            else {
                if(s[i] == ' ')
                    continue;

                if(s[i] == '(')
                    t.push('(');

                else if(s[i] == ')') {
                    while(s.empty() && t.top() != '(') {
                        ve.push_back(string(1, t.top())), t.pop();
                    }
                    t.pop();    
                }

                else {
                    while(!t.empty() && mp[t.top()] >= mp[s[i]] && t.top() != '(') {
                        ve.push_back(string(1, t.top())), t.pop();
                    }
                    if(s[i] == '-') {
                        t.push('+');
                        neg = true;
                    }
                    else
                        t.push(s[i]);
                }
            }
        }

        if(t.empty())
            while(!num.empty()) {
                ve.push_back(num.top()); num.pop();
            }

        while(!t.empty()) {

            ve.push_back(string(1, t.top())), t.pop();
        }

        return evalRPN(ve);
    }
};