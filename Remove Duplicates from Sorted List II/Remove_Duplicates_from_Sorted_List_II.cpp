// Runtime: 12 ms, faster than 56.22% of C++ online submissions for Remove Duplicates from Sorted List II.
// Memory Usage: 9.4 MB, less than 9.71% of C++ online submissions for Remove Duplicates from Sorted List II.

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode dummyHead(0);
        dummyHead->next = head;

        ListNode* curNode = head;
        ListNode* preNode = &dummyHead;

        while(curNode)
        {
            if (curNode->next && curNode->val != curNode->next->val)    
            {
                preNode = curNode;
                curNode = curNode->next;
            }
            else
            {
                if (curNode->next == nullptr)
                    break;
                else
                {
                    int delValue = curNode->val;
                    while (curNode && curNode->val == delValue)
                    {
                        preNode->next = curNode->next;
                        delete curNode;
                        curNode = preNode->next;
                    }
                }
            }
        }
        return dummyHead.next;
    }
};