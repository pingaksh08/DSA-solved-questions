class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> row,col; // to store unrepeated values of rows and columns
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == 0){
                    row.insert(i); col.insert(j);
                }
            }
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                // if either of the value exists, set m[i][j] == 0
                if(row.find(i) != row.end() or col.find(j) != col.end()){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};