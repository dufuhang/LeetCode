'''
现将数组从小到大排序，然后按顺序两两结合
每组的最小值相加则为最大
'''
class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(sorted(nums)[::2])