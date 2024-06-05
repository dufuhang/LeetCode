```py
'''
flip即将矩阵的每一行水平翻转，即倒序输出
invert将0改为1，1改为0.可以用异或^运算符
在这里使用if-else判断语句便于理解
'''
class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        C = []
        for row in A:
            temp = []
            for i in row[::-1]:
                if i == 0:
                    i = 1
                    temp.append(i)
                else:
                    i = 0
                    temp.append(i)
            C.append(temp)
        return C
```