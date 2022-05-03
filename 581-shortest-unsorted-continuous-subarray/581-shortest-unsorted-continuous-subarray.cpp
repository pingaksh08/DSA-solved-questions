class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      // 2 ptr approach
       vector<int> temp;
       temp = nums;
       sort(temp.begin() , temp.end());
       
        int i=0 , j = nums.size()-1;
        while(i<nums.size() and nums[i] == temp[i]){
            i++;
        }
        
        while(j>=0 and nums[j] == temp[j]){
            j--;
        }
        
        if(i==nums.size()) return 0;
        return j-i+1;
    }
};