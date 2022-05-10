class Solution {
public:
    
    void solve(int start , int k , int n , vector<int> v , vector<vector<int>> &ans){
        if(k<0 or n<0) return;
        if(k==0 and n==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=start ; i<=9 ; i++){
            v.push_back(i); // inserting number in temp vector
            solve(i+1 , k-1 , n-i , v , ans); // recursion call
            v.pop_back(); // backtrack
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> v;
       solve(1 , k , n , v , ans); 
       return ans; 
    }
};