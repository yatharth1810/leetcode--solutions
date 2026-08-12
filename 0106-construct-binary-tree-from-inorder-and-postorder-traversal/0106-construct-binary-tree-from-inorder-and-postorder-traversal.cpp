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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int , int> inMap;
        for(int i = 0; i < inorder.size() ; i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder,0, postorder.size()-1 ,inorder,0,inorder.size()-1 ,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder,int postst,int postend, vector<int> &inorder,int inst,int inend ,map<int , int>& inMap){
        if(postst > postend || inst > inend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inRoot = inMap[root->val];
        int node_on_left = inRoot - inst;

        root->left = buildTree(postorder,postst,postst + node_on_left - 1,inorder, inst, inRoot -1,inMap);
        root->right = buildTree(postorder,postst + node_on_left ,postend - 1,inorder , inRoot + 1,inend , inMap);

        return root;
    }
};