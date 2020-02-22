class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i = 0;
        int j = height.size()-1;
        int Smax = 0;
        while (i < j)
        {
            Smax = height[i] < height[j] ? 
            max(Smax,(j - i) * height[i++]) : 
            max(Smax,(j - i) * height[j--]);
        }
        return Smax;
    }
};