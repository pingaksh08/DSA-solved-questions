// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    /*
    bipartite --> if two colors(0 & 1) are assigned to the vertices, no two adjacent vertices
    should have the same color.
    
    observation --> if graph contains a cycle of odd no. of nodes then only the graph is
    not bipartite, else always bipartite.
    
    we are using DFS
    */
    bool solve(int node, vector<int> &colors, vector<int> adj[]){
        if(colors[node] == -1)
         colors[node] = 0;
         
        for(auto nbr : adj[node]){
            if(colors[nbr] == -1){
                colors[nbr] = 1 - colors[node];
                
                if(!solve(nbr, colors, adj)) return false;
            }
            else if(colors[nbr] == colors[node]) return false;
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colors(V,-1);
	    for(int i=0 ; i<V ; i++){
	        if(!solve(i, colors, adj)){
	            return false;
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends