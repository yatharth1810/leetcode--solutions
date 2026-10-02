class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,bool 
    &pass,int &nit){
        int n = grid.size();
        int m = grid[0].size();   
        nit++;     
        vis[row][col] = 1;
        if((row == 0 || row == grid.size()-1) || (col == 0 || col==grid[0].size()-1)){
            pass = true;
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i = 0; i<4 ; i++){
            int newr = row+delrow[i];
            int newc = col+delcol[i];
            if((newr>=0 && newr<n) && (newc>=0 && newc<m) && !vis[newr][newc] && grid[newr][newc]==1){
                dfs(newr,newc,vis,grid,pass,nit);
            } 
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int row = 0; row<n ; row++){
            for(int col = 0; col<m ; col++){
                bool pass = false;
                int nodes_in_trav = 0;
                if(!vis[row][col] && grid[row][col]==1){
                    dfs(row,col,vis,grid,pass,nodes_in_trav);
                    if(pass == false) total += nodes_in_trav;

                }
            }
        }
        return total;
    }
};