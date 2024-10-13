#include <vector>
using namespace std;

class CustomStack {
public:
    int maxsize;
    vector <int>* ve;

    CustomStack(int maxSize) 
    {
        ve = new vector<int>;
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(ve->size() < maxsize)
            ve->push_back(x);
    }
    
    int pop() {
        if(ve->empty())
            return -1;

        int t = ve->back();
        ve->pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for(int i = 0;i < k && i < ve->size();i++)
            ve->operator[](i) += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */