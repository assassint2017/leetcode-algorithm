// Runtime: 44 ms, faster than 70.65% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 30 MB, less than 0.87% of C++ online submissions for Convert Sorted List to Binary Search Tree.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (head == 0)
            return 0;
        
        // 利用双指针找到链表的中点
        ListNode *slowPtr = head, *fastPtr = head, *prePtr = 0;
        while (fastPtr->next != 0 && fastPtr->next->next != 0)
        {
            prePtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // 建立根节点
        TreeNode *treeNode = new TreeNode(slowPtr->val);

        // 递归的建立左子树
        if (prePtr != 0)
        {
            prePtr->next = 0;
            treeNode->left = sortedListToBST(head);
            prePtr->next = slowPtr;
        }

        // 递归的建立右子树
        if (slowPtr->next != 0)
        {
            treeNode->right = sortedListToBST(slowPtr->next);
        }
        
        return treeNode;
    }
};