class Solution {
public:
            // using dfs
    bool dfs(int node,vector<int> &vis,vector<int>& dfsvis,vector<vector<int>>& graph,vector<int>& check){
        vis[node] = 1;
        dfsvis[node] = 1;
        check[node] = 0;
        for(auto x : graph[node]){
            if(!vis[x]){
                if(dfs(x,vis,dfsvis,graph,check) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(dfsvis[x]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        dfsvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        vector<int> check(n,0);
        vector<int> safeNodes;
        for(int i = 0; i<n ; i++){
            if(!vis[i]){
                dfs(i,vis,dfsvis,graph,check);
            }
        }
        for(int i = 0; i<n ; i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
        
    }
};