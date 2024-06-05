```py
'''
即找出数组中的最大值然后返回下标
'''
class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        temp = A[0]
        for value in A:
            if value > temp:
                temp = value
        return A.index(temp)
        '''
        直接使用自带的函数：
        return A.index(max(A))
        '''
```