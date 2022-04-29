class Solution {
public:
    /*
    bipartite --> if two colors(0 & 1) are assigned to the vertices, no two adjacent vertices
    should have the same color.
    
    observation --> if graph contains a cycle of odd no. of nodes then only the graph is
    not bipartite, else always bipartite.
    
    we are using BFS
    */
    bool solve(int node, vector<int> &color, vector<vector<int>> graph){
        // bfs
        queue<int> q;
        q.push(node);
        color[node] = 0; // assigning initial color as 0
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto nbr : graph[curr]){
                if(color[nbr] == -1){
               // it will assign 1 if color is 0 and vice versa
                    color[nbr] = 1 - color[curr]; 
                    q.push(nbr);
                }
                // if adjacent nodes have same color, return false
                else if(color[nbr] == color[curr]){
                    return false;
                }
            }
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       int V = graph.size(); 
       vector<int> color(V,-1); // to store the colors (0 & 1)
       for(int i=0 ; i<V ; i++){
           if(color[i] == -1){
               if(!solve(i, color, graph)){
                   return false;
               }
           }
       }
        
        return true;
    }
};