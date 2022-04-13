class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v;
        int rs = 0;
        int re = n-1;
        int cs = 0;
        int ce = m-1;
        
        while(rs <= re && cs <= ce){
            for(int col = cs ; col <= ce ; col++){
                if(rs > re || cs > ce) break;
                v.push_back(matrix[rs][col]);
            }
            rs++;
            
            for(int row = rs ; row <= re ; row++){
                if(rs > re || cs > ce) break;
                v.push_back(matrix[row][ce]);
            }
            ce--;
            
            for(int col = ce ; col >= cs ; col--){
                if(rs > re || cs > ce) break;
                v.push_back(matrix[re][col]);
            }
            re--;
            
            for(int row = re ; row >= rs ; row--){
                if(rs > re || cs > ce) break;
                v.push_back(matrix[row][cs]);
            }
            cs++;
        }
        
        return v;
    }
};