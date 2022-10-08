class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int anssum = 0 , n = nums.size() , ans = INT_MAX , newtarget = target;
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<n ; i++){
            newtarget = target - nums[i];
            int low = i+1 , high = n-1;
            while(low < high){
                int twosum = nums[low] + nums[high];
                int currdiff = abs(newtarget - twosum);
                if(twosum == newtarget) return nums[i] + twosum;
                
                if(currdiff < ans){
                    ans = currdiff;
                    anssum = nums[i] + twosum;
                }
                
                if(twosum < newtarget) low++;
                if(twosum > newtarget) high--;
            }
        }
        
        return anssum;
    }
};