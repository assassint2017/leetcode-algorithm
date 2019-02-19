// 题目要求如下
// Follow up:
// Could you do it in O(n) time and O(1) space?
// 大概思路就是把前半部分的链表反向，然后逐个进行判断，最后再把整个链表进行恢复

// 因为是O1的空间复杂度，所以速度慢了一点也是很正常的
// Runtime: 28 ms, faster than 63.04% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 12.8 MB, less than 100.00% of C++ online submissions for Palindrome Linked List.

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
    bool isPalindrome(ListNode* head) 
    {
        // 边界处理，当链表为空或者只有一个单元的时候直接返回
        if (head == 0 || head->next == 0)
            return true;

        // 剩下的链表长度至少为2
        // 使用双指针确定链表的中点
        ListNode *midPtr = head, *fastPtr = head;
        while (fastPtr->next && fastPtr->next->next)
        {
            midPtr = midPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // 判断链表的长度为基数还是偶数
        bool even = fastPtr->next ? true : false;

        // 确定右半部分的头结点
        ListNode *rightHead = midPtr->next;

        // 翻转链表，直到rightHead
        ListNode *preNode = 0, *curNode = head, *nextNode;
        while (curNode != rightHead)
        {
            nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }

        // 确定左半部分的头结点
        ListNode *leftHead = even ? midPtr : midPtr->next;

        // 成对元素的进行判读链表是否是回文的
        bool res = true;
        for (ListNode *templeftHead = leftHead, *temprightHead = rightHead; templeftHead;)
        {
            if (templeftHead->val != temprightHead->val)
            {
                res = false;
                break;
            }
            else
            {
                templeftHead = templeftHead->next;
                temprightHead = temprightHead->next;
            }
        }

        // 恢复链表
        preNode = 0, curNode = midPtr;
        while (curNode)
        {
            nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        midPtr->next = rightHead;

        // 返回判断结果
        return res;
    }
};