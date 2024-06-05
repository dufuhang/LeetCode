## 反转+排序
### 思路
1、要判断一个单词是不是某个单词的后缀，可以将单词反转，就可以将寻找后缀转化为寻找前缀
2、将反转后的单词进行字典排序，那么：如果 t 是 s 的后缀，那么反转之后 t’ 就是 s’ 的前缀。在反转+排序之后，s’ 一定紧跟在 t’ 的后面
```cpp
//反转单词，排序
class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        int N = words.size();
        //定义一个数组存放反转后的单词
        vector<string> reversed_words;
        //反转单词
        for (string w : words)
        {
            reverse(w.begin(), w.end());
            //将反转的单词加入数组
            reversed_words.push_back(w);
        }
        //按字典顺序排序
        sort(reversed_words.begin(), reversed_words.end());
        //记录编码的字符串长度
        int l = 0;
        for (int i = 0; i < N; i++)
        {
            //经过字典排序后，最后一个单词一定会加入索引字符串
            //所以不能是for(int i = 0; i < N - 1; i++),这样循环走不到最后一个单词
            //只能在下面的if语句里单独加一个判断
            if (i + 1 < N && reversed_words[i+1].find(reversed_words[i]) != -1)
            {
                continue;
            }
            else
            {
                l += reversed_words[i].size() + 1;
            } 
        }
        return l;
    }
};
```
## 字典树
### 思路
类似题：
- [208-实现字典树](208-ImplementTrie(PrefixTree).md)
```cpp

```