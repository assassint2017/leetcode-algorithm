// 最简单粗暴的一种方法

// Runtime: 228 ms, faster than 28.76% of C++ online submissions for Design HashMap.
// Memory Usage: 169.8 MB, less than 28.24% of C++ online submissions for Design HashMap.

class MyHashMap 
{
public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {
        array = new int[1000001];
        for (int i = 0; i <= 1000000; i++)
            array[i] = -1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        array[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
       return array[key]; 
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        array[key] = -1;
    }
private:
    int *array;
};


// 第二种思路 
// 冲突解决同样适用开放地址中的线性探测

// Runtime: 128 ms, faster than 100.00% of C++ online submissions for Design HashMap.
// Memory Usage: 49.6 MB, less than 57.25% of C++ online submissions for Design HashMap.

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

struct cell
{
    char status;
    int key;
    int value;
    
    cell() : status('U'), key(0), value(0) {}
};

class MyHashMap 
{
public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {
        length = 20001;
        array = new cell[length]();
    }

    ~MyHashMap()
    {
        delete[] array;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        for (int offset = 1, hashpos = key % length; ; offset++)
        {
            if (array[hashpos].status == 'X' && array[hashpos].key == key)
            {
                array[hashpos].value = value;
                return;
            }
            else if ((array[hashpos].status == 'D' && array[hashpos].key == key) || array[hashpos].status == 'U')
            {
                array[hashpos].status = 'X';
                array[hashpos].key = key;
                array[hashpos].value = value;
                return;
            }
            else
                hashpos = (hashpos + offset) % length;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
        for (int offset = 1, hashpos = key % length; ; offset++)
        {
            if (array[hashpos].status == 'X' && array[hashpos].key == key)
                return array[hashpos].value;
            else if ((array[hashpos].status == 'D' && array[hashpos].key == key) || array[hashpos].status == 'U')
                return -1;
            else
                hashpos = (hashpos + offset) % length;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        for (int offset = 1, hashpos = key % length; ; offset++)
        {
            if (array[hashpos].status == 'X' && array[hashpos].key == key)
            {
                array[hashpos].status = 'D';
                return;
            }
            else if ((array[hashpos].status == 'D' && array[hashpos].key == key) || array[hashpos].status == 'U')
                return;
            else
                hashpos = (hashpos + offset) % length;
        }  
    }
private:
    cell* array;
    int length;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

// 思路三 适用开放地址中的平方探测

// Runtime: 128 ms, faster than 100.00% of C++ online submissions for Design HashMap.
// Memory Usage: 49.6 MB, less than 57.25% of C++ online submissions for Design HashMap.

struct cell
{
    char status;
    int key;
    int value;
    
    cell() : status('U'), key(0), value(0) {}
};

class MyHashMap 
{
public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {
        length = 20001;
        array = new cell[length]();
    }

    ~MyHashMap()
    {
        delete[] array;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        for (int offset = 2, hashpos = key % length, sign = 1; ; offset++)
        {
            if (array[hashpos].status == 'X' && array[hashpos].key == key)
            {
                array[hashpos].value = value;
                return;
            }
            else if ((array[hashpos].status == 'D' && array[hashpos].key == key) || array[hashpos].status == 'U')
            {
                array[hashpos].status = 'X';
                array[hashpos].key = key;
                array[hashpos].value = value;
                return;
            }
            else
            {
                hashpos = (hashpos + sign * (offset / 2) * (offset / 2)) % length;
                sign *= -1;
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
        for (int offset = 2, hashpos = key % length, sign = 1; ; offset++)
        {
            if (array[hashpos].status == 'X' && array[hashpos].key == key)
                return array[hashpos].value;
            else if ((array[hashpos].status == 'D' && array[hashpos].key == key) || array[hashpos].status == 'U')
                return -1;
            else
            {
                hashpos = (hashpos + sign * (offset / 2) * (offset / 2)) % length;
                sign *= -1;
            }
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        for (int offset = 2, hashpos = key % length, sign = 1; ; offset++)
        {
            if (array[hashpos].status == 'X' && array[hashpos].key == key)
            {
                array[hashpos].status = 'D';
                return;
            }
            else if ((array[hashpos].status == 'D' && array[hashpos].key == key) || array[hashpos].status == 'U')
                return;
            else
            {
                hashpos = (hashpos + sign * (offset / 2) * (offset / 2)) % length;
                sign *= -1;
            }
        }  
    }
private:
    cell* array;
    int length;
};