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
    int rheight(TreeNode* node){
        int cnt = 0;
        while(node){
            cnt++;
            node = node->right;
        }
        return cnt;
    }
    int lheight(TreeNode* node){
        int cnt = 0;
        while(node){
            cnt++;
            node = node->left;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = lheight(root);
        int rh = rheight(root);
        if(lh == rh) return (1 << lh)-1; // for power of two

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};