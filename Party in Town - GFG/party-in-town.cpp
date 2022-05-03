// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    // using BFS
    int solve(int node , int n , vector<vector<int>> &adj){
        vector<int> dist(n+1 , INT_MAX); // it stores the dist. b/w two houses
        queue<int> q;
        q.push(node);
        dist[node] = 0; // dist 1--1 is 0
        int temp_ans = 0;
                
        while(q.size()){
            int curr = q.front();
            q.pop();
            
            for(auto nbr : adj[curr]){
                // if dist == INT_MAX, i.e. the house is currently not visited
                if(dist[nbr] == INT_MAX){
                    q.push(nbr); // push curr house in queue
             // dist 1--2--4 is obviously curr dist(2--4) + prev dist(1--2).
                    dist[nbr] = 1 + dist[curr];
                    temp_ans = max(dist[nbr] , temp_ans); // max dist. b/w two houses
                }
            }
            
        }
        
        return temp_ans;
    }

    int partyHouse(int N, vector<vector<int>> &adj){
        // we have to find the min. of max. distances b/w two houses
        int ans = INT_MAX;
        int itm;
        
        for(int i=1 ; i<=N ; i++){
            itm = solve(i , N , adj); // BFS
            ans = min(itm , ans);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends