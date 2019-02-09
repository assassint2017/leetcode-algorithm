// 思路一 on的时间复杂度 on的空间复杂度
// Runtime: 60 ms, faster than 83.33% of C++ online submissions for Reorder List.
// Memory Usage: 11.1 MB, less than 0.92% of C++ online submissions for Reorder List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if (head == 0 || head->next == 0)
            return;

        ListNode *root = head;

        stack<ListNode*> memo;
        while (head != 0)
        {
            memo.push(head);
            head = head->next;
        }

        for (head = root;;)
        {
            ListNode *tail = memo.top();
            memo.pop();
            ListNode *temp = head->next;
            head->next = tail;
            tail->next = temp;
            head = temp;

            if (head->next == tail)
            {
                head->next = 0;
                break;
            }
        }
    }
};

// 思路二 on的时间复杂度 o1的空间复杂度
// Runtime: 56 ms, faster than 100.00% of C++ online submissions for Reorder List.
// Memory Usage: 10.1 MB, less than 0.92% of C++ online submissions for Reorder List.

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        if (head == 0 || head->next == 0 || head->next->next == 0)
            return;

        // 切分链表
        ListNode *slowPtr = head, *fastPtr = head;
        while (fastPtr->next != 0 && fastPtr->next->next != 0)    
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // 逆转后半部分
        ListNode *preNode = slowPtr, *nextNode;
        fastPtr = slowPtr->next;
        slowPtr->next = 0;
        while (fastPtr != 0)
        {
            nextNode = fastPtr->next;
            fastPtr->next = preNode;
            preNode = fastPtr;
            fastPtr = nextNode;
        }
        fastPtr = preNode;

        // 将两个部分链表合并
        slowPtr = head;
        while (slowPtr != fastPtr && slowPtr != 0)
        {
            ListNode *tempFast = fastPtr;
            ListNode *tempSlow = slowPtr;

            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;

            tempFast->next = slowPtr;
            tempSlow->next = tempFast;
        }
        slowPtr = 0;
    }
};