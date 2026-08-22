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
class BSTiterator{
    stack<TreeNode*> st;
    // revrse -> true ==> next gives value in decrasing
    // revrse -> false ==> next gives value in incresing 
    bool reverse = true;
public:
    BSTiterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasnext(){
        return !st.empty();
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
private:
    void pushAll(TreeNode* node){
        for( ;node != NULL ; ){
            st.push(node);
            if(!reverse) node = node->left;
            else node = node->right;
        }
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator left(root,false);
        BSTiterator right(root,true);

        int i = left.next();
        int j = right.next();

        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = left.next();
            else j = right.next();
        }
        return false;
    }
};