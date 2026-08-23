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
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        if(prev != NULL && (root->val < prev->val)){
            // if first violation,
            // mark these as first and middle
            if(first == NULL){
                first = prev;
                middle = root;
            }
            //2nd violation mark root as last
            else{
                last = root;
            }
        }
        //mark the current root as prev for next bigger node
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(last && first) swap(last->val,first->val);
        else swap(first->val,middle->val);  //check if any problem
    }
};