# class Solution:
#     def toLowerCase(self, str):
#         return str.lower()

#计算ASCII码
#A~Z:65-90
#a~z:97-122
class Solution:
    def toLowerCse(self,str):
        result=[]
        for c in str:
            if ord(c) >= 65 and ord(c) <= 90:
                result.append(chr(ord(c) + 32))
            else:
                continue
        #join()函数将序列转换为字符串
        return ''.join(result)
