class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(vector<int>& candidates, int target, int index){
       if(target == 0){
           ans.push_back(v);
       }   
        
       for(int i=index ; i<candidates.size() ; i++){
           // skipping repeating elements
           if(i>index and candidates[i] == candidates[i-1]){
               continue;
           } 
           // we will never get our ans if this condition is true so break out
           if(candidates[i] > target){
               break;
           }
           
           // recursive call with backtrack for left recursion
           v.push_back(candidates[i]);
           solve(candidates, target - candidates[i], i+1);
           v.pop_back();
       }

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};