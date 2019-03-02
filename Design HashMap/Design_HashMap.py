# Runtime: 404 ms, faster than 15.12% of Python3 online submissions for Design HashMap.
# Memory Usage: 18.1 MB, less than 34.48% of Python3 online submissions for Design HashMap.

class cell:
    def __init__(self):
        self.status = 'U'
        self.key = 0
        self.value = 0

class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.length = 20001
        self.array = [cell() for i in range(self.length)]  
        

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        offset = 2
        hashpos = key % self.length
        sign = 1
        while True:
            if self.array[hashpos].status == 'X' and self.array[hashpos].key == key:
                self.array[hashpos].value = value
                return
            elif (self.array[hashpos].status == 'D' and self.array[hashpos].key == key) or self.array[hashpos].status == 'U':
                self.array[hashpos].status = 'X'
                self.array[hashpos].key = key
                self.array[hashpos].value = value
                return
            else:
                hashpos = (hashpos + sign * (offset // 2) ** 2) % self.length
                sign *= -1
            offset += 1

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        offset = 2
        hashpos = key % self.length
        sign = 1
        while True:
            if self.array[hashpos].status == 'X' and self.array[hashpos].key == key:
                return self.array[hashpos].value
            elif (self.array[hashpos].status == 'D' and self.array[hashpos].key == key) or self.array[hashpos].status == 'U':
                return -1
            else:
                hashpos = (hashpos + sign * (offset // 2) ** 2) % self.length
                sign *= -1
            offset += 1
        

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        offset = 2
        hashpos = key % self.length
        sign = 1
        while True:
            if self.array[hashpos].status == 'X' and self.array[hashpos].key == key:
                self.array[hashpos].status = 'D'
                return
            elif (self.array[hashpos].status == 'D' and self.array[hashpos].key == key) or self.array[hashpos].status == 'U':
                return
            else:
                hashpos = (hashpos + sign * (offset // 2) ** 2) % self.length
                sign *= -1
            offset += 1
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)