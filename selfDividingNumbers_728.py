'''
filter()函数用于筛选列表，接收一个函数和一个迭代对象作为参数，将迭代对象的每个值传入函数做判断，然后返回新的迭代对象
在Python2.x中，filter()返回列表，3.x为返回一个迭代对象！！
'''
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
