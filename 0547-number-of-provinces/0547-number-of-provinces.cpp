class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int> &vis,int node){
        int n = adj.size();
        vis[node] = 1;
        for(int j = 0; j<n ;j++){
            if(adj[node][j] == 1 && vis[j] == 0){
                dfs(adj,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i = 0 ; i<n ; i++){
            if(vis[i] == 0){
                dfs(isConnected,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};