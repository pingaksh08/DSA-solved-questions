class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> matrix(n , vector<int> (n));
        int val = 1;
        int rs = 0;
        int re = n-1;
        int cs = 0;
        int ce = n-1;
        
        while(rs <= re && cs <= ce){
            for(int col = cs ; col <= ce ; col++){
                if(rs > re || cs > ce) break;
                matrix[rs][col] = val;
                val++;
            }
            rs++;
            
            for(int row = rs ; row <= re ; row++){
                if(rs > re || cs > ce) break;
                matrix[row][ce] = val;
                val++;
            }
            ce--;
            
            for(int col = ce ; col >= cs ; col--){
                if(rs > re || cs > ce) break;
                matrix[re][col] = val;
                 val++;
            }
            re--;
            
            for(int row = re ; row >= rs ; row--){
                if(rs > re || cs > ce) break;
                matrix[row][cs] = val;
                val++;
            }
            cs++;
        }
        
        return matrix;
    }
};