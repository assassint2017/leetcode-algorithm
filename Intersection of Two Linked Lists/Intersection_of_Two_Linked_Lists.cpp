// 思路一 记录第一个链表的长度和第二个链表的长度
// 然后让长链表的指针先移动几个，然后两个指针同时出发，这样相遇的时候就是交点

// Runtime: 56 ms, faster than 98.55% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 16.8 MB, less than 100.00% of C++ online submissions for Intersection of Two Linked Lists.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // 记录两个链表的长度
        int lena = 0, lenb = 0;
        for (ListNode *temp = headA; temp; temp = temp->next)
            lena++;
        for (ListNode *temp = headB; temp; temp = temp->next)    
            lenb++;
        if (lena == 0 || lenb == 0)
            return 0;
        
        ListNode *longer, *shorter;
        if (lena >= lenb)
            longer = headA, shorter = headB;
        else
            longer = headB, shorter = headA;
        
        for (int i = 0; i < abs(lena - lenb); i++)
            longer = longer->next;
        
        while (longer != shorter)
        {
            longer = longer->next;
            shorter = shorter->next;
        }
        return longer;
    }
};