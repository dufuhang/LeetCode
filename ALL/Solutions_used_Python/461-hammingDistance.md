```py
'''
汉明距离，指两个等长字符相同位置的不同字符的个数，是信息论里的概念。
例：
1011101
1001001
汉明距离为2

bin()函数用于将整数转换为二进制，count方法则是计算字符串里指定的字符或字符串的个数

count函数的语法为：
str.count(sub, start= 0,end=len(string))
sub为要搜索的子字符串，start为开始搜索的位置，默认为0，end为结束位置，默认字符串的最后一个字符

^ 为逻辑运算符，求异或，当两个二进位相异时值为1
'''
class Solution:
    def hammingDistance(self, x, y):
        return bin(x ^ y).count('1')
```