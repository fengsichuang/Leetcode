#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> *st1, *st;
    MyQueue() {
        st1 = new stack<int>(), st = new stack<int>();
    }
    
    void push(int x) {
        st->push(x);
    }
    
    int pop() {
        int size = st->size();
        for(int i = 0;i < size-1;i++) {
            st1->push(st->top());
            st->pop();
        }
        int t = st->top();
        while(!st->empty())
            st->pop();
        while(st1->size()) {
            st->push(st1->top());
            st1->pop();
        }
        return t;
    }
    
    int peek() {
        int size = st->size();
        for(int i = 0;i < size-1;i++) {
            st1->push(st->top());
            st->pop();
        }
        int t = st->top();
        while(st1->size()) {
            st->push(st1->top());
            st1->pop();
        }
        return t;
    }
    
    bool empty() {
        return st->empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */