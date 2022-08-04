class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int index, vector<int> &nums){
       // base case 
       if(index == nums.size()){
           ans.push_back(nums);
           return;
       } 
        
       for(int i=index ; i<nums.size() ; i++){
           swap(nums[index], nums[i]); // a possible permutation
           solve(index+1, nums); // repeating the process for next index
           swap(nums[index], nums[i]); // backtracking after the call
       } 
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};