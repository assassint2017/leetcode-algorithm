// 基本思路是使用两个队列来模拟一个堆栈

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 8.9 MB, less than 68.87% of C++ online submissions for Implement Stack using Queues.

class MyStack 
{
public:
    /** Initialize your data structure here. */
    MyStack() 
    {
        // 因为queue拥有默认构造函数，因此这里其实是不需要任何语句进行初始化的
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        if (empty() || queue2.empty())
            queue1.push(x);
        else
            queue2.push(x);
        
        topElement = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        queue<int> *send, *hold;
        if (queue1.empty())
        {
            send = &queue2;
            hold = &queue1;
        }
        else
        {
            send = &queue1;
            hold = &queue2;
        }

        int res = send->front();
        while (send->size() != 1)
        {
            res = send->front();
            send->pop();
            hold->push(res);
        }

        topElement = res;
        res = send->front();
        send->pop();
        
        return res;
    }
    
    /** Get the top element. */
    int top() 
    {
        return topElement;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        if (queue1.empty() && queue2.empty())
            return true;
        else
            return false;
    }

private:
    queue<int> queue1, queue2;
    int topElement;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */