class Solution {
public:
    
    /*
    At each level of the recursive tree, the size of ds will increase.
    We skip recursion call for repeating indices.
    */
    
    void solve(int index, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=index ; i<nums.size() ; i++){
          if(i != index and nums[i] == nums[i-1]){
              continue;
          }  
          ds.push_back(nums[i]);
          solve(i+1, ds, nums, ans);
          ds.pop_back();  
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, ds, nums, ans);
        return ans;
    }
};