class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        Algo-->
        1. traverse from the back & find the index where the breakpoint occours.
           i.e. arr[i] < arr[i+1]
           
        2. again, traverse from the back and find the index at which the element is just greater 
           than arr[i]. i.e. arr[j] > arr[i]
           
        3. swap(arr[i] , arr[j])
        4. reverse(from i+1 to last) to generate just next greater combination
        */
        
        int n = nums.size();
        int i,j;
        
        for(i=n-2 ; i>=0 ; i--)                           
        {
            if(nums[i] < nums[i+1]) break;
        }
        
        if(i<0) 
            reverse(nums.begin() , nums.end());
        
        else
        {
            for(j=n-1 ; j>i ; j--)                   
            {
                if(nums[j] > nums[i]) break;
            }
            
            swap(nums[i] , nums[j]);               
            reverse(nums.begin() + i + 1 , nums.end()); 
        }  
       
    }
};