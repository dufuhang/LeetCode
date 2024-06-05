### Summary
1、统计给的字符串中每个字母出现的次数，存放在数组中，**注意大小写分开存放**
2、若某个字母出现的次数为偶数次，那么可以全部计入回文串
3、若某个字母出现的次数为奇数次，那么-1之后剩下的偶数个可以计入回文串
4、最后随便选一个第3步中减去的某个字符，将其加到回文串的中间，即长度+1，才是最终结果

**注意⚠️：若没有奇数次的字母，那最后不能+1。**

### 例：
```
‘aabbccc’
aa,bb,cc可构成回文串，再将剩下的那个c加入回文串中间即可
```
```
'aabbcc'
aa,bb,cc可构成回文串，因为没有全都出现了偶数次，所以不必再+1
```
```cpp
class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        if (s.size() == 0) return 0;
        int hasharray[52] = {0};
        //统计字母出现的次数，注意大小写分开
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z') hasharray[s[i] - 'a'] += 1;
            if (s[i] >= 'A' && s[i] <= 'Z') hasharray[s[i] - 'A' + 26] += 1;
        }

        int sum = 0;
        int count = 0;//一共出现过多少次奇数次的字母
        for (int j = 0; j < 52; j++)
        {
            //n&1 与运算，可以判断n是否为偶数。如果是偶数，n&1返回0；否则返回1，为奇数。
            if (!(hasharray[j] & 1)) 
            {
                sum += hasharray[j];
            }
            else
            {
                sum = sum + hasharray[j] - 1;
                count++;
            }
        }
        return count > 0 ? ++sum : sum;
    }
};
```