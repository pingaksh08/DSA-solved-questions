class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& v) {
      int m = v.size();
      int n = v[0].size();
      for(int i=1 ; i<m ; i++){
          for(int j=1 ; j<n ; j++){
              if(v[i][j] != v[i-1][j-1]) return false;
          }
      }
        
        return true;
    }
};