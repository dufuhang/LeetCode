### 思路
1、分别统计词汇表和字母表中每个单词的字母数

2、进行比对，若某个单词中的字母出现的次数都小于或等于，则满足要求，计入长度中

3、因为只有小写字母，所以可以设置一个长度为26的数组，来统计字母数，不必使用哈希表
```cpp
class Solution 
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        int length = 0;
        vector<int> count_chars = count(chars);
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> count_words = count(words[i]);
            if (cmp(count_words, count_chars))
            {
                length += words[i].size();
            }
        }
        return length;
    }

    bool cmp(const vector<int>& vec_words, const vector<int>& vec_chars)
    {
        for (int i = 0; i < 26; i++)
        {
            if (vec_words[i] > vec_chars[i])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> count(string& str)
    {
        vector<int> vec(26, 0);
        for (char c : str)
        {
            vec[c - 'a']++;
        }
        return vec;
    }
};
```