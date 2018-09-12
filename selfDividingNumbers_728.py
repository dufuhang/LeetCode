class Solution:
    def is_selfDividingNumbers(self,num):
        for i in str(num):
            if i == '0' or num % int(i) !=0:
                return False
        return True
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        return list(filter(self.is_selfDividingNumbers,range(left,right+1)))
