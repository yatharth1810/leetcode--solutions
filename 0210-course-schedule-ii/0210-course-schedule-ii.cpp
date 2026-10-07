class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for(auto edge : prerequisites) {
        int course = edge[0];
        int prerequisite = edge[1];

        adj[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        order.push_back(node);

        for(int next : adj[node]) {
            indegree[next]--;

            if(indegree[next] == 0)
                q.push(next);
        }
    }
    if(order.size() == numCourses) return order;
    return {};

    }
};