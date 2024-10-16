#include <bits/stdc++.h>
#define fr s[front]
#define bc s[back]
#define delta ('a' - 'A')

using namespace std;

class Solution {
public:
    bool InNum(char t) {
        return t >= '0' && t <= '9';
    }

    bool Upper(char t) {
        return t >= 'A' && t <= 'Z';
    }

    bool Lower(char t) {
        return t >= 'a' && t <= 'z';
    }

    bool isPalindrome(string s) {
        int front = 0, back = s.size()-1;
        while(front < back) {
            while(front < s.size() && !InNum(fr) && !Upper(fr) && !Lower(fr)) 
                front++;
            while(back >= 0 && !InNum(bc) && !Upper(bc) && !Lower(bc)) 
                back--;

            if(front >= s.size() || back < 0)
                return true;

            if(InNum(fr)) { 
                if(fr == bc)
                    front++, back--;
                else
                    return false;
            }

            else if(Upper(fr))
                if(fr == bc || (fr + delta == bc))
                    front++, back--;
                else
                    return false;

            else
                if(fr == bc || (fr - delta == bc))
                    front++, back--;
                else
                    return false;
            }
        return true;
    }
};