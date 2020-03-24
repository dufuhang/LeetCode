```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //返回当前节点的最大深度
    int depth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans,l+r+1);
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        ans = 0;
        depth(root);
        return ans - 1;
    }
private:
    //全局变量，记录当前已遍历的两个节点之间的路径的最大值
    int ans;
};
```