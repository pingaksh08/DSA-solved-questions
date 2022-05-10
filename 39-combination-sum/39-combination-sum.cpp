class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(vector<int>& candidates, int target , int start){
        // base case
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        for(int i=start ; i<candidates.size() ; i++){
            if(candidates[i] > target) break; // absurd or invalid value for ans
            
            v.push_back(candidates[i]); // inserting values in temp vector
            solve(candidates , target - candidates[i] , i); // recursion
            v.pop_back(); // backtracking
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        solve(candidates , target , 0);
        return ans;
    }
};