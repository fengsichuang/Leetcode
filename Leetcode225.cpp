#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> *q;
    MyStack() {
        q = new queue<int>();
    }
    
    void push(int x) {
        q->push(x);
    }
    
    int pop() {
        int s = q->size();
        for(int i = 0;i < s-1;i++) {
            q->push(q->front());
            q->pop();
        }
        int t = q->front();
        q->pop();
        return t;
    }
    
    int top() {
        return q->back();
    }
    
    bool empty() {
        return q->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    auto t = MyStack();
    t.push(2);
    t.pop();
    t.empty();
}