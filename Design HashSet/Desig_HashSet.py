# 思路二的py代码

# Runtime: 192 ms, faster than 48.21% of Python3 online submissions for Design HashSet.
# Memory Usage: 17.3 MB, less than 41.46% of Python3 online submissions for Design HashSet.

class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.length = 20001
        self.array = [['U', 0] for i in range(self.length)]
        

    def add(self, key: int) -> None:
        hashpos = key % self.length
        offset = 1
        while True:
            if self.array[hashpos][0] == 'X' and self.array[hashpos][1] == key:
                return
            elif (self.array[hashpos][0] == 'D' and self.array[hashpos][1] == key) or self.array[hashpos][0] == 'U':
                self.array[hashpos][0] = 'X'
                self.array[hashpos][1] = key
            else:
                hashpos = (hashpos + offset) % self.length
            offset += 1

    def remove(self, key: int) -> None:
        hashpos = key % self.length
        offset = 1
        while True:
            if self.array[hashpos][0] == 'X' and self.array[hashpos][1] == key:
                self.array[hashpos][0] = 'D'
                return
            elif (self.array[hashpos][0] == 'D' and self.array[hashpos][1] == key) or self.array[hashpos][0] == 'U':
                return
            else:
                hashpos = (hashpos + offset) % self.length
            offset += 1

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        hashpos = key % self.length
        offset = 1
        while True:
            if self.array[hashpos][0] == 'X' and self.array[hashpos][1] == key:
                return True
            elif (self.array[hashpos][0] == 'D' and self.array[hashpos][1] == key) or self.array[hashpos][0] == 'U':
                return False
            else:
                hashpos = (hashpos + offset) % self.length
            offset += 1

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)