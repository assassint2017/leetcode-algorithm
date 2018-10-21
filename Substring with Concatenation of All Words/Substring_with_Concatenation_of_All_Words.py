# 360ms 66.91%
class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []
        num_words = len(words)
        len_words = len(words[0])
        counter = {}  # 当做一个计数器
        for word in words:
            if word in counter:
                counter[word] += 1
            else:
                counter[word] = 1
        start_index = []
        for i in range(len(s) - num_words * len_words + 1):
            temp_counter, used_words = {}, 0
            for j in range(i, i + (num_words - 1) * len_words + 1, len_words):
                word = s[j:j+len_words]
                if word in counter:
                    if word in temp_counter:
                        temp_counter[word] += 1
                        if temp_counter[word] > counter[word]:
                            break
                        used_words += 1
                    else:
                        temp_counter[word] = 1
                        used_words += 1
                else:
                    break
            if used_words == num_words:
                start_index.append(i)
        return start_index