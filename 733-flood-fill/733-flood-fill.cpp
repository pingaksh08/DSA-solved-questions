class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, vector<vector<int>> &vis, int orgcolor){
        if(sr<0 or sr>=n or sc<0 or sc>=m or vis[sr][sc] or image[sr][sc] != orgcolor){
            return ;
        }
        
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        
        dfs(image, sr+1, sc, color, n, m, vis, orgcolor);
        dfs(image, sr-1, sc, color, n, m, vis, orgcolor);
        dfs(image, sr, sc+1, color, n, m, vis, orgcolor);
        dfs(image, sr, sc-1, color, n, m, vis, orgcolor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int orgcolor = image[sr][sc];
        dfs(image, sr, sc, color, n, m, vis, orgcolor);
        return image;
    }
};