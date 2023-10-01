class MyCircularQueue {
private:
    vector<int> data;
    int size;
    int front;
    int rear;
    bool full;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        size = 0;
        front = 0;
        rear = -1;
        full = false;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % data.size();
        data[rear] = value;
        size++;
        if (size == data.size()) {
            full = true;
        }
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % data.size();
        size--;
        full = false;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return full;
    }
};
