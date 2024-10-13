#define PUSH "Push"
#define POP "Pop"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int now = 1;
        vector<string> ve;
        for(int i = 0;i < target.size();i++) {
            while(target[i] != now) {
                now++;
                ve.push_back(PUSH), ve.push_back(POP);
            }
            ve.push_back(PUSH);
            now++;
        }
        return ve;
    }
};

int main()
{
    Solution slu;
    vector<int> ve = {1,3};
    auto temp = slu.buildArray(ve,3);
    for(auto &i : temp)
        cout << i << ' ';
    cout << '\n';
}