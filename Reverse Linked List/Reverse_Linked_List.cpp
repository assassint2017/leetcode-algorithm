// 递推版本的

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.4 MB, less than 6.09% of C++ online submissions for Reverse Linked List.

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* preNode = nullptr;
        ListNode* curNode = head;
        ListNode* nextNode = nullptr;

        while (curNode)
        {
            nextNode = curNode->next;
            curNode->next = preNode;

            preNode = curNode;
            curNode = nextNode;
        }
        return preNode;
    }
};


// 递归版本的
// Runtime: 12 ms, faster than 40.31% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.4 MB, less than 8.00% of C++ online submissions for Reverse Linked List.
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
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* tail = head->next;
        head->next = nullptr;
        ListNode* reverseHead = reverseList(tail);
        tail->next = head;

        return reverseHead;
    }
};