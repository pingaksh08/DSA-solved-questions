class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = INT_MAX , ans = -1;
        for(int i=0 ; i<nums.size() ; i++){
            mini = min(mini , nums[i]);
            ans = max(ans , nums[i] - mini);
        }
        if(ans == 0) return -1;
        return ans;
    }
};