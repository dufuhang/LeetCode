```cpp
class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        if (s.empty()) return ;
        int first = 0;
        int second = s.size() - 1;
        while (first < second)
        {
            swap(s[first], s[second]);
            first++;
            second--;
        }
    }
};
```