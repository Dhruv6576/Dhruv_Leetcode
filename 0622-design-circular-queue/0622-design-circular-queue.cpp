class MyCircularQueue {
public:
    vector<int> q;
    int f, r, s, n;

    MyCircularQueue(int k) {
        n = k;
        q.resize(k);
        f = 0;
        r = -1;
        s = 0;
    }
    
    bool enQueue(int v) {
        if (isFull()) return false;
        r = (r + 1) % n;
        q[r] = v;
        s++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        f = (f + 1) % n;
        s--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[f];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == n;
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