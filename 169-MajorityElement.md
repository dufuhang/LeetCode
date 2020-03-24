## unordered_map
- **C++ 11**标准中加入了unordered系列的容器。

    从查找、插入上来说，unordered_map的效率都优于hash_map，更优于map；
    而空间复杂度方面，hash_map最低，unordered_map次之，map最大。
- unordered_map与map的对比：

    unordered_map存储时是**根据key的hash值判断元素是否相同**，即unordered_map内部元素是无序的，而map中的元素是**按照二叉搜索树存储（用红黑树实现）**，进行中序遍历会得到有序遍历。所以使用时map的key需要定义operator<。而unordered_map需要定义hash_value函数并且重载operator==。但是很多系统内置的数据类型都自带这些。

- unordered_map与hash_map对比：

    unordered_map原来属于boost分支和std::tr1中，而hash_map属于非标准容器。
unordered_map感觉速度和hash_map差不多，但是支持string做key，也可以使用复杂的对象作为key。
　　unordered_map编译时gxx需要添加编译选项：--std=c++11
```cpp
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size() / 2;
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i] += 1;
            if (mp[i] > n) return i;
        }
        return -1;
    }
};
```
## 排序
一个众数元素的个数超过整个数组大小的一半，那么数组的一半或一半以上都是这个众数元素，所以下标为`nums.size() / 2`的位置必然是该元素
```cpp
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
```
## 