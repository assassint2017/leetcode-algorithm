// 实现循环队列 阿里面试题

// Runtime: 32 ms, faster than 84.47% of C++ online submissions for Design Circular Queue.
// Memory Usage: 16.5 MB, less than 72.73% of C++ online submissions for Design Circular Queue.

class MyCircularQueue 
{
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : data(k + 1, 0)
    {
        front = 0;
        rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) 
    {
        if (!isFull())
        {
            rear = (rear + 1) % data.size();
            data[rear] = value;

            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() 
    {
        if (!isEmpty())
        {
            front = (front + 1) % data.size();
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() 
    {
        if (!isEmpty())
        {
            return data[(front + 1) % data.size()];
        }
        else
        {
            return -1;
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() 
    {
        if (!isEmpty())
        {
            return data[rear];
        }
        else
        {
            return -1;
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() 
    {
        return rear == front;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() 
    {
        return (rear + 1) % data.size() == front;
    }
private:
    int front;  // 头部索引
    int rear;  // 尾部索引

    vector<int> data;  // 数据存储
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