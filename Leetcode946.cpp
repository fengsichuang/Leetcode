#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> st;
        int p = 0;
        for(int i = 0;i < popped.size();i++) {
            while(st.empty() || popped[i] != st.top()) {
                if(p < pushed.size()) {
                    st.push(pushed[p]);
                    p++;
                }
                else
                    return false;
            }
            st.pop();
        }
        return true;
    }
};

int main()
{
    vector<int> pu = {1,2,3,4,5}, po = {4,3,5,1,2};
    Solution slu;
    cout << (slu.validateStackSequences(pu,po) ? 'T' : 'F') << '\n';
}