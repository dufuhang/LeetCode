class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0,j = 0;j < A.size();j++)
        {
            if (A[j] % 2 == 0)
            {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
                i++;
            }
        }
        return A;
    }
};