class MyCircularDeque {
public:
    int *data;
    int maxSize, size, front, back;
    MyCircularDeque(int k) {
        maxSize = k, size = 0;
        data = new int[k+5];
        front = back = 0;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        front--;
        if(front < 0)
            front = maxSize-1;
        if(isEmpty())
            back = front;
        data[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        back++;
        if(back >= maxSize)
            back = 0;
        if(isEmpty())
            front = back;
        data[back] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        front++;
        if(front >= maxSize)
            front = 0;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        back--;
        if(back < 0)
            back = maxSize-1;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return data[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return data[back];
    }
    
    bool isEmpty() {
        return size == 0 ? true : false;
    }
    
    bool isFull() {
        return size == maxSize ? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */