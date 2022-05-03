// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    // DFS
    void solve(int i , int j ,  vector<vector<int>> &visited ,vector<vector<char>>& grid , int n , int m ){
        if(i<0 or j<0 or i>n-1 or j>m-1) return;
        if(grid[i][j] == '0' or visited[i][j] == 1) return;
        
            visited[i][j] = 1;
            solve(i-1 , j , visited , grid , n , m);
            solve(i , j-1 , visited , grid , n , m);
            solve(i+1 , j , visited , grid , n , m);
            solve(i , j+1 , visited , grid , n , m);
            solve(i-1 , j-1 , visited , grid , n , m);
            solve(i-1 , j+1 , visited , grid , n , m);
            solve(i+1 , j-1 , visited , grid , n , m);
            solve(i+1 , j+1 , visited , grid , n , m);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
       // travel through all 8 directions when founded an unvisited & m[i][j] == 1
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int> (m,0));
        
        int count=0;
         for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(visited[i][j] == 0 and grid[i][j] == '1'){
                    solve(i , j , visited , grid , n , m);
                    count++;
                }
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends