// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool solve(int node , vector<int> &visited , int parent , vector<int> adj[]){
        visited[node] = 1;
        /*
        2 conditions to check for cycle -->
        1. the nbr should not be visited
        2. the nbr should not be the parent of the current node
        */
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
               if(solve(nbr , visited , node , adj)){
                   return true;
               }
            }
            else if(nbr != parent){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // can be solved through dfs
        vector<int> visited(V,0);
        for(int i=0 ; i<V ; ++i){
            if(!visited[i]){
                bool have_cycle = solve(i , visited , -1 , adj);
                if(have_cycle)
                 return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends