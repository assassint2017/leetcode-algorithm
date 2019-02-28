// 基本思路 使用两个堆栈来模拟队列

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 9 MB, less than 49.26% of C++ online submissions for Implement Queue using Stacks.

class MyQueue 
{
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        if (empty())
            topElement = x;

        else if (stack1.empty())
        {
            topElement = stack2.top();
            while (!stack2.empty())
            {
                int temp = stack2.top();
                stack2.pop();
                stack1.push(temp);
            }
        }

        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        if (!stack2.empty())
        {
            int res = stack2.top();
            stack2.pop();

            if (!stack2.empty())
                topElement = stack2.top();
            return res;
        }
        else
        {
            int temp;
            while (stack1.size() != 1)
            {
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp)
            }

            topElement = temp;

            int res = stack1.top();
            stack1.pop();
            return res;
        }
        
    }
    
    /** Get the front element. */
    int peek() 
    {
        return topElement;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        if (stack1.empty() && stack2.empty())
            return true;
        else
            return false;
    }

private:
    stack<int> stack1, stack2;
    int topElement;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */