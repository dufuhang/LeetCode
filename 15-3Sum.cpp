//思路：
//根据题目要求，3个数和为0，且结果集中不包含重复的三元组。
//由此联想到 Two Sum 这道题。从第一个数开始遍历，假定这个数是给定的值，那就只需要再寻找两个值即可，就变成了 Two Sum 问题
//同时，因为不能包含重复的三元组，可将数组进行排序，使相同的数字相邻，就可以很容易的在每次移动指向元素的指针时，判断是否与上一个数相同
//若相同，直接跳过。
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //存放结果
        vector<vector<int>> res;
        //对数组进行排序.
        sort(nums.begin(), nums.end());
        //数组大小
        int size = nums.size();
        //从头开始遍历
        for (int i = 0; i < size; i++)
        {
            //定义前后两个指针
            int front = i + 1;
            int back = size - 1;
            //减去当前元素值外的目标值
            int target = 0 - nums[i];
            //只要front < back,则持续遍历
            while (front < back)
            {
                //计算两指针所指的和
                int sum = nums[front] + nums[back];
                //判断与目标值的大小。小，说明需要更大的值，将front++；反之将back--
                if (sum < target)
                {
                    front++;
                }
                else if (sum > target)
                {
                    back--;
                }
                else //相等，符合要求，记录入临时数组，然后传入结果数组
                {
                    //临时存储结果
                    vector<int> vec(3, 0);
                    vec[0] = nums[i];
                    vec[1] = nums[front];
                    vec[2] = nums[back];
                    res.push_back(vec);
                    //将front，back同时移动，并跳过重复的元素
                    while (front < back && nums[front] == vec[1])
                    {
                        front++;
                    }
                    while (front < back && nums[back] == vec[2])
                    {
                        back--;
                    }
                }
                //将第一个数字后移，判断是否重复
                while (i + 1 < size && nums[i + 1] == nums[i])
                {
                    i++;
                }
            }
        }
        return res;
    }
};