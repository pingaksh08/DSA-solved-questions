class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        Approach is similar to 3 sum, 
        we compare target-a-b with c+d and when the match is founded,
        we push it in our answer. Also, we skip the repeating elements.
        */
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<n ; i++){
            long long int tar1 = target - nums[i];
            for(int j=i+1 ; j<n ; j++){
                // initial target
                long long int itm_target = tar1 - nums[j];
                int low = j+1 , high = n-1;
                // 2 sum approach
                while(low < high){
                    // secondary target sum
                    int two_sum = nums[low] + nums[high];
                    
                    if(two_sum < itm_target) low++;
                    else if(two_sum > itm_target) high--;
                    
                    else{
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        
                        // skipping repeating elements for c and d
                        while(low < high and nums[low] == temp[2]) low++;
                        while(low < high and nums[high] == temp[3]) high--;
                    }
                }
                // skipping repaeting elements for b
                while(j+1 < n and nums[j] == nums[j+1]) j++;
            }
            // skipping repeating elements for a
            while(i+1 < n and nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};