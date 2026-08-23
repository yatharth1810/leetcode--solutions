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
class Nodevalue{
public:
    int maxNode,minNode,sum;

    Nodevalue(int sum,int minNode,int maxNode){
        this->sum = sum;
        this->minNode = minNode;
        this->maxNode = maxNode;
    }
};
class Solution {
int maxsum = 0;
public:
    Nodevalue postorder(TreeNode* root){
        if(!root) return Nodevalue(0,INT_MAX,INT_MIN);
        
        auto left = postorder(root->left);
        auto right = postorder(root->right);

        if(left.maxNode < root->val && right.minNode > root->val){
        //means that bst is valid
            int currsum = root->val + left.sum + right.sum;
            maxsum = max(currsum,maxsum);
            return Nodevalue(currsum,min(left.minNode,root->val),max(right.maxNode,root->val));
        }
        return Nodevalue(0,INT_MIN,INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        maxsum = 0;
        postorder(root);
        return maxsum;
    }
};