#include <bits/stdc++.h>

class MyCircularQueue {
public:
    int *data;
    int size, maxSize, back, front;
    MyCircularQueue(int k) {
        data = new int[k];
        maxSize = k, size = 0;
        back = front = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) 
            return false;
        
        back++;
        if(back >= maxSize)
            back = 0;
        if(isEmpty())
            front = back;
        size++, data[back] = value;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        front++;
        if(front >= maxSize)
            front = 0;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return data[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return data[back];
    }
    
    bool isEmpty() {
        return size == 0 ? true : false;
    }
    
    bool isFull() {
        return maxSize == size ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */