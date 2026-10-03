class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;   //{{row,col},time}
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntfresh = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col<m ; col++){
                if(grid[row][col] == 2){
                    vis[row][col] = 2;
                    q.push({{row,col},0});
                }
                else if(grid[row][col] == 1) cntfresh++;
            }
        }
        if(cntfresh == 0) return 0;
        //bfs
        int total_t = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            total_t = max(t,total_t);
            q.pop();
            for(int i = 0; i<4 ; i++){
                int newr = r + delrow[i];
                int newc = c + delcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] == 1 && !vis[newr][newc]){
                    vis[newr][newc] = 2;
                    cnt++;
                    q.push({{newr,newc},t+1});  
                }
            }

        }
        if(cnt != cntfresh) return -1;
        else return total_t;
    }
};