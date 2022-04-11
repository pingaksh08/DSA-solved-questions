class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        /*
         Approach -->
         Store all the elements in a temporary array,then assign the values to
         the grid matrix from the array from length l-k.
        */
        int n = grid.size();
        int m = grid[0].size();
        int l = n*m;
        k = k%l; // so k don't go out of bound
        
        if(k == 0)
            return grid;
        
        int itm[l];
        int index = 0;
        // inserting elements in a temp array
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                itm[index] = grid[i][j];
                index++;
            }
        }
        
        index = l-k;
        // assigning shifted values to the grid
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                grid[i][j] = itm[index];
                index = (index+1)%l; // so index don't go out of bound
            }
        }
        
        return grid;
    }
};