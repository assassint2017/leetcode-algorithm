// 最简单粗暴的方法 可见占用的内存和速度都是很差的

// Runtime: 228 ms, faster than 14.73% of C++ online submissions for Design HashSet.
// Memory Usage: 145.4 MB, less than 16.66% of C++ online submissions for Design HashSet.

class MyHashSet 
{
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        array = new int[1000001];
        for (int i = 0; i <= 1000000; i++)
            array[i] = -1;
    }
    
    void add(int key) 
    {
        array[key] = 1;
    }
    
    void remove(int key) 
    {
       array[key] = -1; 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        if (array[key] == -1)
            return false;
        else
            return true;
    }
private:
    int *array;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */

// 第二种思路
// 冲突处理使用开放地址法中的线性探测

// Runtime: 108 ms, faster than 100.00% of C++ online submissions for Design HashSet.
// Memory Usage: 40.8 MB, less than 44.05% of C++ online submissions for Design HashSet.

class MyHashSet 
{
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        // 使用字符来代表key的状态 X表示占用 D表示删除 U表示空位
        // 这里把装载因子设定在至少为0.5
        length = 20001;
        array = new pair<char, int>[length];
        for (int i = 0; i < length; i++)
        {
            array[i].first = 'U';
            array[i].second = 0;
        }
    }

    ~MyHashSet()
    {
        delete[] array;
    }
    
    void add(int key) 
    {
        for (int offset = 1, hashpos = key % length; ; offset++)
        {
            if (array[hashpos].first == 'X' && array[hashpos].second == key)
                return;
            else if ((array[hashpos].first == 'D' && array[hashpos].second == key) || array[hashpos].first == 'U')
            {
                array[hashpos].first = 'X';
                array[hashpos].second = key;
                return;
            }
            else
                hashpos = (hashpos + offset) % length;
        }
    }
    
    void remove(int key) 
    {
        for (int offset = 1, hashpos = key % length; ; offset++)
        {
            if (array[hashpos].first == 'X' && array[hashpos].second == key)
            {
                array[hashpos].first = 'D';
                return;
            }
            else if ((array[hashpos].first == 'D' && array[hashpos].second == key) || array[hashpos].first == 'U')
                return;
            else
                hashpos = (hashpos + offset) % length;
        }   
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        for (int offset = 1, hashpos = key % length; ; offset++)
        {
            if (array[hashpos].first == 'X' && array[hashpos].second == key)
                return true;
            else if ((array[hashpos].first == 'D' && array[hashpos].second == key) || array[hashpos].first == 'U')
                return false;
            else
                hashpos = (hashpos + offset) % length;
        }
    }
private:
    pair<char, int>* array;
    int length;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */