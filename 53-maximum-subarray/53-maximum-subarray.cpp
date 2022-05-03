class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kandane's algo
        int isum=0 , ans = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            isum += nums[i];
            ans = max(ans , isum);
            // if intermediate sum goes -ve, don't consider it
            if(isum < 0)
                isum=0;
        }
        
        return ans;
    }
};