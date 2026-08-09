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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int x = 0;
        unordered_map<TreeNode*,TreeNode*> parent;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q1;
        q1.push(target);
        visited[target] = true;
        while(!q1.empty()){
            int size = q1.size();

            for(int i = 0; i<size ; i++){
                if(x == k){
                    while(!q1.empty()){
                        ans.push_back(q1.front()->val);
                        q1.pop();
                    }
                    return ans;
                }    
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left  && !visited[node->left]){
                    q1.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q1.push(node->right);
                    visited[node->right] = true;;
                }
                if(parent[node] && !visited[parent[node]]){
                    q1.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            x++;
            
        }
        return ans;
    }
};