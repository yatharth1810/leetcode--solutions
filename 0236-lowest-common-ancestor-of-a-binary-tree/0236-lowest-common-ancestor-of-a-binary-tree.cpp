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
    TreeNode* common(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL || root == p || root == q) return root;
        

        TreeNode* l = common(root->left,p,q);
        TreeNode* r = common(root->right,p,q);

        if(l != NULL && r != NULL) return root;

        return (l != NULL) ? l : r;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return common(root,p,q);
        
    }
};