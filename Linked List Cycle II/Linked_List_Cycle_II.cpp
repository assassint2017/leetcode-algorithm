// 双指针
// Runtime: 12 ms, faster than 29.54% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 6.7 MB, less than 0.89% of C++ online submissions for Linked List Cycle II.

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
    ListNode *detectCycle(ListNode *head) 
    {
        if (head == 0)
            return 0;

        ListNode *fastPtr = head, *slowPtr = head;
        
        bool hasCycle = false;
        while (slowPtr->next != 0 && fastPtr->next != 0 && fastPtr->next->next !=0)
        {
            // 慢指针每次一共一格，快指针每次移动两格
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if (fastPtr == slowPtr)
            {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle == false)
            return 0;

        // 此时链表中存在环
        fastPtr = head;
        while(slowPtr != fastPtr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return fastPtr;
    }
};