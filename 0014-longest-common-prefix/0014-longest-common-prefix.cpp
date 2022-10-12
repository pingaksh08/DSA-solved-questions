class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int len = v[0].length() , n = v.size();
        for(int i=1 ; i<n ; i++){
            int j = 0;
            while(j < v[i].length() and v[i][j] == v[0][j]) j++;
            len = min(len , j);
        }
        
        return v[0].substr(0 , len);
    }
};