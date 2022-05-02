class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // 2 ptr approach
        int i=0, j=nums.size()-1;
        while(i < j){
            if((nums[i]&1) && !(nums[j]&1)){
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }
            
            else if(!(nums[i]&1) && (nums[j]&1)){   
                i++;
                j--;
            }
            
            else if((nums[i]&1) && (nums[j]&1)){
                j--;
            }
            
            else {
                i++;
            }
        }
        
        return nums;
    }
};