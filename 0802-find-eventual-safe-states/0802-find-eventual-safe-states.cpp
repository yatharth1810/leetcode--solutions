class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverse(graph.size());
        vector<int> indegree(n);
        for(int i = 0; i<graph.size(); i++){
            for(auto it : graph[i]){
                reverse[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;
        for(int i = 0; i<n ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int a = 0,b = safeNodes.size();
            
            safeNodes.push_back(node);
            for(auto it : reverse[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};