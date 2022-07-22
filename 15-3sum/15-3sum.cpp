class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        initially, sort the array then tackle a variable and then the problem is same as 2sum
        also, take care of repeating elements
        */
       vector<vector<int>> ans;
       sort(nums.begin() , nums.end());
       for(int i=0 ; i<nums.size()-2 ; i++){
           // if the adjacent variables are not same, then only
           if(i==0 or (i>0 and nums[i] != nums[i-1])){
               int low = i+1 , high = nums.size()-1 , val = -nums[i];
               while(low < high){
                   if(nums[low] + nums[high] < val) low++;
                   else if(nums[low] + nums[high] > val) high--;
                   else{
                       ans.push_back({nums[i] , nums[low] , nums[high]}); // ans set
                   // to skip the repeating elements
                   while(low < high and nums[low] == nums[low+1]) low++;
                   while(low < high and nums[high] == nums[high-1]) high--;
                   
                   low++; high--;
                   }     
               }
           }
       }
        
        return ans;
    }
};