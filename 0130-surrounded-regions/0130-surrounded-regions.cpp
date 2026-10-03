class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i = 0; i<4 ; i++){
            int newr = row+delrow[i];
            int newc = col+delcol[i];

            if(newr>=0 && newc>=0 && newr<n && newc<m && !vis[newr][newc] && board[newr][newc] == 'O'){
                dfs(newr,newc,vis,board);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int r = 0; r<n ; r++){
            for(int c = 0; c<m ; c++){
                if(r == 0 || r ==n-1 || c == 0 || c == m-1){
                    if(!vis[r][c] && board[r][c] == 'O'){
                        dfs(r,c,vis,board);
                    }
                }
            }
        }
        for(int r = 0; r<n ; r++){
            for(int c = 0; c<m ;c++){
                if(!vis[r][c] && board[r][c]=='O'){
                    board[r][c] = 'X';
                }
            }
        }

    }
};