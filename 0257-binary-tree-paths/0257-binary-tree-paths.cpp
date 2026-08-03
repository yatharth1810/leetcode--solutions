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
    void recurr(vector<string> &ans,TreeNode* root,string st){
        if(root->left == NULL && root->right == NULL){
            st += to_string(root->val)
            ;
            ans.push_back(st);
            return;
        }
        st += to_string(root->val)+ "->";

        if(root->left) recurr(ans,root->left,st);
        if(root->right) recurr(ans,root->right,st);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        string st = "";
        recurr(ans,root,st);
        return ans;
    }
};