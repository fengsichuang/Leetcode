#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string s; stack<char> st;
        for(int i = 0;i < chars.size();i++) {
            int j = i+1, cnt = 1;
            s.push_back(chars[i]);
            while(j < chars.size() && chars[j] == chars[i])
                cnt++, j++;
            i = j-1;
            if(cnt != 1) {
                while(cnt) {
                    st.push(cnt % 10 + '0'), cnt /= 10;
                }
            }
            while(!st.empty()) {
                s.push_back(st.top());
                st.pop();
            }
        }
        chars.clear();
        for(auto &i : s)
            chars.push_back(i);
        return chars.size();
    }
};