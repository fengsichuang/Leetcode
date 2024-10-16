#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string str;     vector<string> ans;
        for(auto &i : words) {
            str += i;
            str += '|';
        }

        for(auto &i : words) {
            int first = str.find(i);
            if(str.find(i, first+i.size()) != string::npos) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};