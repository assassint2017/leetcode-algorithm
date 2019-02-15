// 链表的插入排序

// Runtime: 48 ms, faster than 75.93% of C++ online submissions for Insertion Sort List.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Insertion Sort List.

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
    ListNode* insertionSortList(ListNode* head) 
    {
        // 如果只有一个元素或者没有元素的话直接返回即可，不需要排序
        if (head == 0 || head->next == 0)
            return head;

        for (ListNode *preNode = 0, *curNode = head, *nextNode = head; curNode; curNode = nextNode)
        {
            nextNode = nextNode->next;

            // 迭代寻找适合的插入位置
            ListNode *leftNode = 0, *rightNode = head;
            bool insert = false;
            while (rightNode != curNode)
            {
                if (rightNode->val <= curNode->val)
                {
                    leftNode = rightNode;
                    rightNode = rightNode->next;
                }
                else
                {
                    insert = true;
                    curNode->next = rightNode;
                    
                    if (leftNode)
                        leftNode->next = curNode;
                    else
                        head = curNode;

                    preNode->next = nextNode;
                    break;
                }
            }

            if (!insert)
                preNode = curNode;
        }
        return head;    
    }
};