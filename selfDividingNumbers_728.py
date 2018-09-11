class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        result=[]
        for num in range(left,right+1):
            temp=[]
            for i in str(num):
                if num % int(i) == 0 and i != '0':
                    temp.append(i)
                else:
                    break
            result.append(''.join(temp)
        print(result) 

s = Solution()
s.selfDividingNumbers(1,22)
