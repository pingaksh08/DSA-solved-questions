class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(vector<int>& candidates, int target , int index){
        // base case
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(v);
            }
            return;
        }
        
        if(candidates[index] <= target){
            v.push_back(candidates[index]); // inserting values in temp vector
            solve(candidates , target - candidates[index] , index); // when element is picked
            v.pop_back(); // backtracking (deleting prev value as the left recursion in eliminated)
        }
        
        solve(candidates , target , index+1); // when element is not picked
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates , target , 0);
        return ans;
    }
};