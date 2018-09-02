'''
set()创建一个无序不重复的元素集，可进行关系测试，删除重复数据，还可以计算
交集，差集，并集等
本题使用了可以删除重复元素的特性，将传入的words表中以每个元素为单位的将字母转换成
莫尔斯电码传入列表temp，再以元素为单位将分离的摩尔斯电码合并传入新的列表transformations。
最后将列表transformations转换成set，自动剔除重复的元素，那么set表的长度即为所求值。
'''
class Solution:
    def uniqueMorseRepresentations(self, words):
        d = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        transformations = []
        for str in words:
            temp = []
            for i in str:
                temp.append(d[ord(i) - 97])
            transformations.append(''.join(temp))
        return len(set(transformations))
            
            