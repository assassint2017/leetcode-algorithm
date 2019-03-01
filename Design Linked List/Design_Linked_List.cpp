// 使用单向链表就足够了

// Runtime: 48 ms, faster than 100.00% of C++ online submissions for Design Linked List.
// Memory Usage: 19.4 MB, less than 73.75% of C++ online submissions for Design Linked List.

struct LinkNode
{
    LinkNode(int num) : val(num), next(0) {}
    int val;
    LinkNode *next;
};


class MyLinkedList 
{
public:
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        length = 0;
        tail = dummyhead = new LinkNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        if (index >= 0 && index < length)
        {
            LinkNode *temp = dummyhead;
            while (index-- >= 0)
                temp = temp->next;
            return temp->val;
        }
        else
            return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        LinkNode *temp = new LinkNode(val);

        if (tail == dummyhead)
            tail = temp;

        temp->next = dummyhead->next;
        dummyhead->next = temp;

        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        LinkNode *temp = new LinkNode(val);
        tail->next = temp;
        tail = temp;

        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if (index < 0 || index > length)
            return;
        else if (index == 0)
            addAtHead(val);
        else if (index == length)
            addAtTail(val);
        else
        {
            LinkNode *addNode = new LinkNode(val);
            
            LinkNode *preNode = dummyhead;
            while (index-- > 0)
                preNode = preNode->next;

            addNode->next = preNode->next;
            preNode->next = addNode;

            length++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if (index < 0 || index >= length)
            return;
        else
        {
            int temp = index;
            
            LinkNode *preNode = dummyhead;
            while (index-- > 0)
                preNode = preNode->next;

            if (temp == length - 1)
                tail = preNode;
            
            LinkNode *delNode = preNode->next;
            preNode->next = delNode->next;

            delete delNode;
            length--;
        }
    }
private:

    // 链表的长度
    int length;
    LinkNode *dummyhead, *tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */