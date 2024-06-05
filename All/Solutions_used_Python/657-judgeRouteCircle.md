```py
'''
只要判断字符中相反的路径，比如R和L，U和D的出现次数是否相等即可
'''
class Solution:
    def judgeCircle(self, moves):
        numR = moves.count('R')
        numL = moves.count('L')
        numU = moves.count('U')
        numD = moves.count('D')
        if numR == numL and numU == numD:
            return True
        else:
            return False
```