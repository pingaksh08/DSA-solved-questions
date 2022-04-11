class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // math based ques
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n , vector<int> (m));
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int newcol = (j+k)%m; // updated column index
                int newrow = (i + (j+k)/m)%n; // updated row index
                ans[newrow][newcol] = grid[i][j];
            }
        }
        
        return ans;
        
    }
};