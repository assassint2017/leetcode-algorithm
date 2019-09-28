// 其实并不难，就是比较麻烦，如果非要说技巧，应该是单链表翻转的时候如何把头结点的next指针置空
// Runtime: 16 ms, faster than 96.91% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 9.9 MB, less than 35.48% of C++ online submissions for Reverse Nodes in k-Group.

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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {   
        // 首先统计一下链表的长度
        int length = 0;
        ListNode* temp = head;
        while (temp)
        {
            ++length;
            temp = temp->next;
        }
        
        // 边界条件处理
        if (head == nullptr || k <= 0 || k > length) return head;
        
        ListNode dummyHead(666);
        ListNode* preHead = &dummyHead;
        
        int numOfLeft = length;
        ListNode *preNode = nullptr, *curNode = head, *nextNode = nullptr;
        
        while (numOfLeft)
        {
            if (numOfLeft < k) break;
            
            ListNode *curHead = curNode, *curTail = nullptr;
            
            for (int i = 0; i < k; ++i)
            {   
                nextNode = curNode->next;
                curNode->next = preNode;
                
                preNode = curNode;
                curNode = nextNode;
                
                --numOfLeft;
            }

            curTail = preNode;
            
            preHead->next = curTail;
            curHead->next = curNode;
            
            preHead = curHead;
        }
        
        return dummyHead.next;
    }
};