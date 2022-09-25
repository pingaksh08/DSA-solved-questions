class MyCircularQueue {
public:
    vector<int> q;
    int start = 0 , length = 0;
    
    MyCircularQueue(int k) : q(k) {
        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[(start + length) % q.size()] = value;
        length++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        start = (start+1) % q.size();
        --length;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[start];
    }
    
    int Rear() {
       if(isEmpty()) return -1;
       return q[(start + length - 1) % q.size()]; 
    }
    
    bool isEmpty() {
        return !length;
    }
    
    bool isFull() {
        return length == q.size();
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