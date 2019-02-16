// 一种思路是使用字典来记录原始节点和复制节点的链接关系，这样时间复杂度为O(2n) 空间复杂度也是线性的
// Runtime: 64 ms, faster than 63.88% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 17.9 MB, less than 100.00% of C++ online submissions for Copy List with Random Pointer.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if (head == 0)
            return 0;

        // 建立哈希表
        unordered_map<RandomListNode*, RandomListNode*> hashTable;
        
        RandomListNode *copyHead = new RandomListNode(head->label);
        hashTable.insert(pair<RandomListNode*, RandomListNode*>(head, copyHead));
        
        RandomListNode *preNode = copyHead, *originNode = head->next;

        // 第一遍循环首先把节点都复制一遍
        while (originNode)
        {
            RandomListNode *node = new RandomListNode(originNode->label);
            hashTable.insert(pair<RandomListNode*, RandomListNode*>(originNode, node));
            preNode->next = node;
            preNode = node;
            originNode = originNode->next;
        }

        // 第二遍循环搞定随机指针
        RandomListNode *copyNode = copyHead;
        originNode = head;
        
        while (originNode)
        {
            if (originNode->random)
            {   
                auto iter = hashTable.find(originNode->random);
                copyNode->random = iter->second; 
            }
                          
            copyNode = copyNode->next;
            originNode = originNode->next;
        }
        
        return copyHead;
    }
};

// 第二种思路
// 另外一个思路比较奇特，将复制的节点和原始节点组成一个单链表，这样时间复杂度为O(3n)，空间复杂度为O(1)

// Runtime: 60 ms, faster than 100.00% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 16.9 MB, less than 100.00% of C++ online submissions for Copy List with Random Pointer.

class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if (head == 0)
            return 0;
        
        // 第一次遍历复制节点
        RandomListNode *originNode = head;
        while (originNode)
        {
            RandomListNode *copyNode = new RandomListNode(originNode->label);
            copyNode->next = originNode->next;
            originNode->next = copyNode;

            originNode = originNode->next->next;
        }
            
        // 第二次遍历搞定随机指针
        originNode = head;
        while (originNode)
        {
            if (originNode->random)
                originNode->next->random = originNode->random->next;
            originNode = originNode->next->next;
        }

        // 第三次遍历恢复原始链表
        RandomListNode *dummyNode = new RandomListNode(0);
        RandomListNode preNode = dummyNode;
        for (; head; head = head->next)
        {
            RandomListNode *copyNode = head->next;
            head->next = copyNode->next;
            copyNode->next = 0;

            preNode->next = copyNode;
            preNode = copyNode;
        }
        return dummyNode->next;
    }
};