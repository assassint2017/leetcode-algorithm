// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Partition List.
// Memory Usage: 8.5 MB, less than 94.05% of C++ online submissions for Partition List.

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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode small(0), big(0);
        ListNode *smallPtr = &small, *bigPtr = &big;
        while (head)
        {
            if (head->val < x)
            {
                smallPtr->next = head;
                head = head->next;
                smallPtr = smallPtr->next;
                smallPtr->next = nullptr;
            }
            else
            {
                bigPtr->next = head;
                head = head->next;
                bigPtr = bigPtr->next;
                bigPtr->next = nullptr;
            }
        }
        smallPtr->next = big.next;
        return small.next;
    }
};