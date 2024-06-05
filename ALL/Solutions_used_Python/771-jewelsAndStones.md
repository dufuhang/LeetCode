```py
class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        num = 0
        strS = set([i for i in J])
        for i in S:
            if i in strS:
                num += 1
        return num
'''
使用set剔除重复的字符，避免重复计算导致错误
'''
```      