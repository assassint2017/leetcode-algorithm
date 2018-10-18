# 44ms 82.97%
class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        split_list = path.split('/')
        
        index = 1
        while index <= len(split_list) - 1:
            if split_list[index] == '.' or split_list[index] == '':
                del split_list[index]
            elif split_list[index] == '..':
                del split_list[index]
                if index > 1:
                    del split_list[index - 1]
                    index -= 1
            else:
                index += 1
                
        res = ''.join([item + '/' for item in split_list])
        
        if len(res) > 1:
            return res[:-1]
        else:
            return res