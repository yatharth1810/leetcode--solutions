class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& vis,int color,int incolor){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        for(int i = 0; i<4; i++){
            int newr = row + delrow[i];
            int newc = col + delcol[i];
            if(newr<n && newr>=0 && newc<m && newc>=0 && (incolor == image[newr][newc]) && vis[newr][newc] == 0){
                dfs(newr,newc,image,vis,color,incolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc]; 
        if(initialcolor == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        dfs(sr,sc,image,vis,color,initialcolor);
        return image;

    }
};