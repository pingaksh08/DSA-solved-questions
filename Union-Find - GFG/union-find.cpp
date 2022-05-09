// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
     int find_parent(int node , int par[]){
        // if the node is single node
        if(node == par[node]){
            return node;
        }
        
        // path compression ==> 2-->3-->5-->7 then whay not make 2-->7 , 3-->7 , 5-->7
        return par[node] = find_parent(par[node] , par);
    }
    
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        // get parent of a and b from par array
        a = find_parent(a , par);
        b = find_parent(b , par);
        
        // a --> b
        if(rank1[a] > rank1[b]){
            par[b] = a;
        }
        
        // b --> a
        else if(rank1[a] < rank1[b]){
            par[a] = b;
        }
        
        // at same rank, make any one parent and increase its rank 
        else{
            par[b] = a;
            rank1[a]++;
        }
    }
    
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        // if parents of both x and y are same, means they are connected
        return (find_parent(x , par) == find_parent(y , par));
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends