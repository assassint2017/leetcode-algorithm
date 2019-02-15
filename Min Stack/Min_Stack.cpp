// 利用链表实现一个最小堆栈
// 思路十分巧妙

// Runtime: 40 ms, faster than 92.40% of C++ online submissions for Min Stack.
// Memory Usage: 17.1 MB, less than 100.00% of C++ online submissions for Min Stack.

struct linkNode
{
    int val;
    linkNode *next;
    linkNode(int value)
    {
        val = value;
        next = 0;
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        head = new linkNode(0);
        minvalue = INT_MAX;
    }
    
    void push(int x) 
    {
        if (x <= minvalue)
        {
            linkNode *tempNode = new linkNode(minvalue);
            if (empty())
                head->next = tempNode;
            else
            {
                tempNode->next = head->next;
                head->next = tempNode;
            }
            minvalue = x;
        }

        linkNode *tempNode = new linkNode(x);
        if (empty())
            head->next = tempNode;
        else
        {
            tempNode->next = head->next;
            head->next = tempNode;
        }
    }
    
    void pop() 
    {
        if (!empty())
        {
            if (head->next->val == minvalue)
            {
                linkNode *deleteNode = head->next;
                head->next = deleteNode->next;
                delete deleteNode;
                minvalue = head->next->val;
            }

            linkNode *deleteNode = head->next;
            head->next = deleteNode->next;
            delete deleteNode;
        }    
    }
    
    int top() 
    {
        return head->next->val;
    }
    
    int getMin() 
    {
        return minvalue;
    }

private:
    linkNode *head;
    int minvalue;

    bool empty()
    {
        if (head->next == 0)
            return true;
        else 
            return false;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */