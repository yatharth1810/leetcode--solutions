class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i<numCourses ;i++){
            if(!indegree[i]) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto x : adj[node]){
                indegree[x]--;
                if(!indegree[x]) q.push(x);
            }
        }
        if(cnt == numCourses)return true;
        return false;
    }
};