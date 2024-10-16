#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0;i < haystack.size();i++) {
            int j = 0;  bool find = true;
            for(j = 0;j < needle.size();j++) {
                if(i+j >= haystack.size() || haystack[i+j] != needle[j]) {
                    find = false;   break;
                }
            }

            if(find)
                return i;
        }
        return -1;
    }
};