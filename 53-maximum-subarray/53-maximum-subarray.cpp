class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int itmsum=0, maxt = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            itmsum += nums[i];
            maxt = max(maxt , itmsum);
            
            // whenever itmsum goes -ve, don't consider it
            if(itmsum < 0)
                itmsum=0;
        }
        return maxt;
    }
};