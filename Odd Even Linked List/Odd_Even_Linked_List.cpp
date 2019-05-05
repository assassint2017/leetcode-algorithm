// Runtime: 16 ms, faster than 99.93% of C++ online submissions for Odd Even Linked List.
// Memory Usage: 9.8 MB, less than 97.96% of C++ online submissions for Odd Even Linked List.

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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode oddHead(0);
        ListNode evenHead(0);

        ListNode* oddptr = &oddHead;
        ListNode* evenptr = &evenHead;

        while (head)
        {
            oddptr->next = head;
            oddptr = oddptr->next;
            head = head->next;

            if (head == nullptr)
                break;

            evenptr->next = head;
            evenptr = evenptr->next;
            head = head->next;
        }

        evenptr->next = nullptr;
        oddptr->next = evenHead.next;
        return oddHead.next;
    }
};