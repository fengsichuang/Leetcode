#include <vector>

using namespace std;

struct node
{   
    int val;
    int lastMin;

    node(int x,int y)
    {
        val = x, lastMin = y;
    }
};


class MinStack {
public:
    vector <node> * ve;
    int min = 0x7fffffff;

    MinStack() {
        ve = new vector<node>;
    }
    
    void push(int val) {
        node temp(val, getMin());
        ve->push_back(temp);
    }
    
    void pop() {
        ve->pop_back();
    }
    
    int top() {
        if(ve->empty())
            return -1;
        
        return ve->back().val;
    }
    
    int getMin() {
        if(ve->empty())
            return __INT_MAX__;
        
        return ve->back().val > ve->back().lastMin ? ve->back().lastMin : ve->back().val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */