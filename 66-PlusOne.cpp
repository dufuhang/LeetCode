class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        //获取vector长度
        int length = digits.size();
        //从尾向前遍历
        for (int i = length-1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};