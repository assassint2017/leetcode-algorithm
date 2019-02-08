// 双指针 一个快指针，一个慢指针
// Runtime: 12 ms, faster than 26.05% of C++ online submissions for Linked List Cycle.
// Memory Usage: 6.7 MB, less than 0.69% of C++ online submissions for Linked List Cycle.

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
    bool hasCycle(ListNode *head) 
    {
        if (head == 0)
            return false;

        ListNode *fastPtr = head->next, *slowPtr = head;
        
        while (slowPtr != fastPtr)
        {
            if (slowPtr->next != 0 && fastPtr->next != 0 && fastPtr->next->next !=0)
            {
                // 慢指针每次一共一格，快指针每次移动两格
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
            }
            else
                return false;    
        }
        return true;
    }
};