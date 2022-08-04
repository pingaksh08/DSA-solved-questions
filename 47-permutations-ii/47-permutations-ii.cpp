class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index, vector<int> &nums){
       // base case 
       if(index == nums.size()){
           ans.push_back(nums);
           return;
       } 
       // using set to avoid duplicates 
       unordered_set<int> s; 
       for(int i=index ; i<nums.size() ; i++){
           // skipping the similar elements
           if(s.count(nums[i]) == 1) continue;
           s.insert(nums[i]);
           swap(nums[index], nums[i]); // a possible permutation
           solve(index+1, nums); // repeating the process for next index
           swap(nums[index], nums[i]); // backtracking after the call
       } 
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       sort(nums.begin() , nums.end()); 
       solve(0, nums);
       return ans;
    }
};