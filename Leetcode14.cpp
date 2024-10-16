#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonString;
        int pos = 0;    char t;

        while(1) {
            t = strs.front()[pos];
            for(auto &i : strs) {
                if(pos >= i.size() || i[pos] != t)
                    return commonString;
            }
            pos++;
            commonString += t;
        }

        return commonString;
    }
};