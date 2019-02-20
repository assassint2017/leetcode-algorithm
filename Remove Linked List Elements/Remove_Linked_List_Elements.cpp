// 最简单的链表的题目 纯粹是用来练手的
// 对于这种链表的题目来说，新建一个哑节点有时候是非常方便的

// Runtime: 36 ms, faster than 81.62% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 11.6 MB, less than 11.82% of C++ online submissions for Remove Linked List Elements.

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
    ListNode* removeElements(ListNode* head, int val) 
    {
        // 建立一个哑节点
        ListNode dummyHead(0);
        dummyHead.next = head;

        for (ListNode *preNode = &dummyHead; head;)
        {
            if (head->val == val)
            {
                preNode->next = head->next;
                delete head;
                head = preNode->next;
            }
            else
            {
                preNode = head;
                head = head->next;
            }
        }
        return dummyHead.next;
    }
};