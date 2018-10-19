# 44ms 79.66%
class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res_list = []
        def dfs(strs, temp_str):
            if not strs or temp_str.count('.') is 4:
                if not strs and temp_str.count('.') is 4:
                    res_list.append(temp_str)
                return
            if strs[0] is '0':
                dfs(strs[1:], temp_str + '0.')
            else:
                dfs(strs[1:], temp_str + strs[:1] + '.')
                if len(strs) >= 2:
                    dfs(strs[2:], temp_str + strs[:2] + '.')
                if len(strs) >= 3 and '100' <= strs[:3] <= '255':
                    dfs(strs[3:], temp_str + strs[:3] + '.')
        dfs(s, '')
        return [strs[:-1] for strs in res_list]