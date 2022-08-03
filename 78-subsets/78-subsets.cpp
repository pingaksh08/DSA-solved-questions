class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(int index, vector<int> &nums){
        if(index == nums.size()){
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[index]);
        solve(index+1, nums);
        v.pop_back(); // so that when left recursion ends func. calls itself for right recursion
        solve(index+1, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;
    }
};