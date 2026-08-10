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

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* st;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) st = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left); 
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        q.push(st);
        unordered_map<TreeNode*,bool> visited;
        visited[st] = true;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i = 0;i<size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                    flag = 1;
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                    flag = 1;
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    flag = 1;
                }
            }
            if(flag) time++;
        }
        return time;
    }
};