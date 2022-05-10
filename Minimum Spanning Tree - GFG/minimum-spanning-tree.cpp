// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // PRIMS'S ALGORITHM
        vector<int> parent(V,-1); // to store the parent of the node
        vector<int> key(V , INT_MAX); // to store min. weight 
        vector<bool> mstvisit(V , false); // to mark the visit of the node in mst
        //min heap
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        key[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            int curr_node = pq.top().second; // get the node
            pq.pop();
            mstvisit[curr_node] = true; // mark it visited
            
            for(auto it : adj[curr_node]){
                int node = it[0];
                int weight = it[1];
                
                // if the node is not visited in mst and a smaller wt is found then
                if(mstvisit[node] == false and weight < key[node]){
                    key[node] = weight; // update the min wt
                    parent[node] = curr_node; // update the parent
                    pq.push({key[node] , node}); // push the node, wt pair in the pq
                }
            }
        }
        int sum=0;
        for(int i=0 ; i<key.size() ; i++){
            sum += key[i];
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends