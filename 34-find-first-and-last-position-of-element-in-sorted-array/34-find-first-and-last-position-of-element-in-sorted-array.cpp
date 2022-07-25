class Solution {
public:
    
    int firstocc(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    int lastocc(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int a1 = firstocc(nums , target);
        int a2 = lastocc(nums , target);
        return {a1,a2};
    }
};