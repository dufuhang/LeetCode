'''
仍然使用了zip()函数，将矩阵转置即可
'''
class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        return list(zip(*A))