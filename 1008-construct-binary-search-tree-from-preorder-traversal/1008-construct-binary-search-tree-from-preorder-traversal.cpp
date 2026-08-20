/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub = INT_MAX;
        int i = 0;
        return construct(preorder,i,ub);
    }
    TreeNode* construct(vector<int> &preorder,int &i ,int ub){
        if(i == preorder.size() || preorder[i] > ub) return NULL;
        int x = preorder[i];
        TreeNode* node = new TreeNode(preorder[i++]);
        
        node->left = construct(preorder,i,x);
        node->right = construct(preorder,i,ub);
        return node;
    }
};