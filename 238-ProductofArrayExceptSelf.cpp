//[a1    ,a2    ,a3    ,a4    ]

//[a2a3a4,a1a3a4,a1a2a4,a1a2a3]
//fvec:
//[1     ,a1    ,a1a2  ,a1a2a3]
//bvec:
//[a2a3a4,a3a4  ,a4    ,1     ]
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        //从前往后遍历的乘积
        vector<int> fvec(n, 1);
        //从后往前遍历的乘积
        vector<int> bvec(n, 1);
        //存放结果的数组
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++)
        {
            fvec[i] = fvec[i-1] * nums[i-1];
        }
        
        for (int i = n - 2; i >= 0 ; i--)
        {
            bvec[i] = bvec[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < n; i++)
        {
            res[i] = fvec[i] * bvec[i];
        }
        return res;
    }
};