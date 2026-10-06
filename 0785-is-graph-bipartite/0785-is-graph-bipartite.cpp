class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int> &color){
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(auto it: graph[x]){
                if(color[it] == -1){
                    color[it] = !color[x];
                    q.push(it);
                }
                else if(color[it] == color[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i = 0; i<n ; i++){
            if(color[i] == -1){
                color[i] = 0;

                if(!bfs(i,graph,color)){
                    return false;
                }
            } 
        }
        return true;
    }
};