class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        for(int r=0 ; r<n ; r++){
            for(int c=0 ; c<m ; c++){
                if(mat[r][c] == 0){
                    ans[r][c] = 0;
                    vis[r][c] = 1;
                    q.push({{r,c},0});
                }
            }
        }    
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1}; 
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int i = 0; i<4 ; i++){
                int newr = r + delrow[i];
                int newc = c + delcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && mat[newr][newc] == 1){
                    q.push({{newr,newc},dis+1});
                    ans[newr][newc] = dis+1;
                    vis[newr][newc] = 1;
                }
            }
        }
        return ans;
    }
};