//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void solve(int i , int j , int n , vector<vector<int>> &m , string curr){
      // base cases
      if(i < 0 or j < 0 or i == n or j==n or m[i][j] == 0){
          return;
      }
      else if(i == n-1 and j == n-1){
          ans.push_back(curr);
          return;
      }
      else{
          m[i][j] = 0;
          
          //down
          curr.push_back('D');
          solve(i+1 , j , n , m , curr);
          curr.pop_back();
          
          //left
          curr.push_back('L');
          solve(i, j-1 , n , m , curr);
          curr.pop_back();
          
          //right
          curr.push_back('R');
          solve(i , j+1 , n , m , curr);
          curr.pop_back();
          
          //up
          curr.push_back('U');
          solve(i-1 , j , n , m , curr);
          curr.pop_back();
          
          m[i][j] = 1;
      }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string curr = "";
        solve(0 , 0 , n , m , curr);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends