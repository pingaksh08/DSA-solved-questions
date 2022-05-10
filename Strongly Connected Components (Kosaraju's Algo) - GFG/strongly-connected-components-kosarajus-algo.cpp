// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    /*
    KOSARAJU'S ALGO
    3 steps-->
    1. sort nodes in order of finishing time(topo sort)
    2. transpose the graph
    3. call rev dfs on the sorted finishing time
    */ 
	void dfs(int src , stack<int> &st , vector<bool> &visited , vector<int> adj[]){
	    visited[src] = true;
	    for(auto nbr : adj[src]){
	        if(!visited[nbr]){
	            dfs(nbr , st,  visited , adj);
	        }
	    }
	    
	    st.push(src);
	}
	
	void revdfs(int src , vector<bool> &visited , vector<int> transAdj[]){
	     visited[src] = true;
	    for(auto nbr : transAdj[src]){
	        if(!visited[nbr]){
	            revdfs(nbr , visited , transAdj);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
    	vector<bool> visited(V,false);
    	stack<int> st;
    		
        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                dfs(i , st , visited , adj);
            }
        }
        
        vector<int> transAdj[V];
        for(int i=0 ; i<V ; i++){
            visited[i] = false;
            for(auto it : adj[i]){
                transAdj[it].push_back(i);
            }
        }
        
        int count=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                count++;
                revdfs(node , visited , transAdj);
            }
        }
        
        return count;
        
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends