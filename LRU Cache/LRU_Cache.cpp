// 使用双向链表和哈希表共同实现
// typedef 如果写在函数外部，作用范围就是本文件
// 如果写在函数内，作用范围本函数
// 如果写在类内，且是公有，就可以在类外用className::typename来调用，如果是私有，当然也就不行了

// Runtime: 120 ms, faster than 40.72% of C++ online submissions for LRU Cache.
// Memory Usage: 40 MB, less than 32.93% of C++ online submissions for LRU Cache.

class LRUCache 
{
public:
    LRUCache(int capacity) 
    {
        maxSize = capacity;
    }
    
    int get(int key) 
    {
        auto iter = hashmap.find(key);
        if (iter == hashmap.end())
        {
            return -1;
        }
        else
        {
            update(iter);
            return iter->second.first;
        }
    }
    
    void put(int key, int value) 
    {
        auto iter = hashmap.find(key);
        if (iter == hashmap.end())
        {
            if (hashmap.size() == maxSize)
            {
                int key = queue.back();
                queue.pop_back();
                hashmap.erase(key);
            }

            queue.push_front(key);
            hashmap.insert(pair<int, pa>(key, pa(value, queue.begin())));
        }
        else
        {
            iter->second.first = value;
            update(iter);
        }
    }
private:
    typedef list<int>::iterator lit;
    typedef pair<int, lit> pa;
private:
    void update(unordered_map<int, pa>::iterator iter)
    {
        int key = iter->first;

        queue.erase(iter->second.second);

        queue.push_front(key);

        iter->second.second = queue.begin();
    }
private:
    int maxSize;
    list<int> queue;
    unordered_map<int, pa> hashmap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */