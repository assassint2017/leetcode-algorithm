// 其实题目中限制了不能对原始链表进行修改反倒是好事，这样就容易了很多
// 实践之后发现把问题想的太简单了，这样写最大的问题就是很容易溢出
// 1560 / 1563 test cases passed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        long long sum1 = 0, sum2 = 0;
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        while (ptr1)
        {
            sum1 *= 10;
            sum1 += ptr1->val;
            ptr1 = ptr1->next;
        }
        
        while (ptr2)
        {
            sum2 *= 10;
            sum2 += ptr2->val;
            ptr2 = ptr2->next;
        }
        
        long long res = sum1 + sum2;

        // 根据计算出来的和，构建链表
        ListNode dummyHead(0);

        while (res != 0)
        {
            int val = res % 10;

            ListNode* node = new ListNode(val);
            ListNode* temp = dummyHead.next;

            dummyHead.next = node;
            node->next = temp;

            res /= 10;
        }
        return dummyHead.next;
    }
};


// 所以使用堆栈来模拟加法过程
// Runtime: 24 ms, faster than 74.03% of C++ online submissions for Add Two Numbers II.
// Memory Usage: 13 MB, less than 51.85% of C++ online submissions for Add Two Numbers II.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<ListNode*> stack1, stack2;

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        while (ptr1)
        {
            stack1.push(ptr1);
            ptr1 = ptr1->next;
        }

        while (ptr2)
        {
            stack2.push(ptr2);
            ptr2 = ptr2->next;
        }

        int base = 0, carry = 0;
        ListNode dummyHead(0);
        while (!stack1.empty() && !stack2.empty())
        {
            ptr1 = stack1.top();
            stack1.pop();

            ptr2 = stack2.top();
            stack2.pop();

            base = (ptr1->val + ptr2->val + carry) % 10;
            carry = (ptr1->val + ptr2->val + carry) / 10;
            
            ListNode* node = new ListNode(base);
            ListNode* temp = dummyHead.next;

            dummyHead.next = node;
            node->next = temp;
        }

        while (!stack1.empty())
        {
            ptr1 = stack1.top();
            stack1.pop();

            base = (ptr1->val + carry) % 10;
            carry = (ptr1->val + carry) / 10;
            
            ListNode* node = new ListNode(base);
            ListNode* temp = dummyHead.next;

            dummyHead.next = node;
            node->next = temp;
        }

        while (!stack2.empty())
        {
            ptr2 = stack2.top();
            stack2.pop();

            base = (ptr2->val + carry) % 10;
            carry = (ptr2->val + carry) / 10;
            
            ListNode* node = new ListNode(base);
            ListNode* temp = dummyHead.next;

            dummyHead.next = node;
            node->next = temp;
        }

        // 这里要特别注意一下 [5]+[5]=[1][0]
        if (carry != 0)
        {
            ListNode* node = new ListNode(carry);
            ListNode* temp = dummyHead.next;

            dummyHead.next = node;
            node->next = temp;
        }

        return dummyHead.next;
    }
};