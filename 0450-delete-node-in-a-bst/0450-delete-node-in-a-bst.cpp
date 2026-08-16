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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root->val == key) return helper(root);

        TreeNode* dummyhead = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right != nullptr && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummyhead;
    }
    TreeNode* helper(TreeNode* root){
        if(root == NULL) return root;
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }

        TreeNode* RightChild = root->right;
        TreeNode* LastLeftRight = lastright(root->left);
        LastLeftRight->right = RightChild;
        return root->left;
    }
    TreeNode* lastright(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return lastright(root->right);
    }
};