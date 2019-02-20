// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 9.1 MB, less than 63.42% of C++ online submissions for Delete Node in a Linked List.

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
    void deleteNode(ListNode* node) 
    {
        for (ListNode *nextNode = 0; ; )
        {
            nextNode = node->next;
            node->val = nextNode->val;

            if (nextNode->next)
                node = nextNode;
            else
            {
                node->next = 0;
                delete nextNode;
                break;
            }
        }
    }
};