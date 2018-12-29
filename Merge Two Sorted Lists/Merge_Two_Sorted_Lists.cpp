// 第一种思路，完全新建一个链表，不去破坏原始的两个小链表
// 12ms 43.69%

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {   
        ListNode *head = new ListNode(0), *rear = head;
        
        // 循环判断直到两个链表有一个为空
        while (l1 && l2)
        {
            int minValue;
            
            if (l1->val <= l2->val)
            {
                minValue = l1->val;
                l1 = l1->next;
            }
            else
            {
                minValue = l2->val;
                l2 = l2->next;
            }
                
            rear->next = new ListNode(minValue);
            rear = rear->next;
        }
        
        // 将剩下的链表接到总链表的后边
        for (ListNode *rest = l1 ? l1 : l2;rest;rest = rest->next)
        {
            rear->next = new ListNode(rest->val);
            rear = rear->next;
        }
        
        return head->next;
    }
};

// 第二种思路，破坏原始的两个小链表，将一个链表插入到另外一个链表中
// 12ms 43.69%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *head;
        if (l1->val > l2->val)
        {
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;                      
        }
        head = l1;
        
        // 循环插入直到两个链表有一个为空
        while(l1 && l2)
        {
            while (l1->next && l1->next->val <= l2->val)
                l1 = l1->next;
            
            if (!l1->next)break;
            
            ListNode *temp = l2;
            l2 = l2->next;
            
            temp->next = l1->next;
            l1->next = temp;
            
            l1 = l1->next;      
        }
        
        // 将剩下的链表接到总链表的后边
        if (!l1->next)
            l1->next = l2; 
        return head;
    }
};
