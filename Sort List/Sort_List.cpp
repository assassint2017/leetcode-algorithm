// 解决方案是归并排序，对于链表的归并排序，空间复杂度为常数!!!
// Runtime: 44 ms, faster than 99.38% of C++ online submissions for Sort List.
// Memory Usage: 11.5 MB, less than 93.72% of C++ online submissions for Sort List.

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
    ListNode* sortList(ListNode* head) 
    {
        // 如果链表为空或者只有一个节点，直接返回即可
        if (head == nullptr || head->next == nullptr)
            return head;

        // 使用双指针来将一个完整的链表一分为二
        ListNode* slowPtr = head, *fastPtr = head;
        ListNode* preNode = nullptr;
        while (fastptr != nullptr && fastPtr->next != nullptr)
        {
            preNode = solwPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        preNode->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slowPtr);
        
        return merge(left, right);
    }
private:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummyHead(0);
        ListNode* head = &dummyHead;

        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                head->next = left;
                head = head->next;
                left = left->next;
            }
            else
            {
                head->next = right;
                head = head->next;
                right = right->next;
            }
        }

        if (left != nullptr)
            head->next = left;
        if (right != nullptr)
            head->next = right;

        return dummyHead.next;
    }
};