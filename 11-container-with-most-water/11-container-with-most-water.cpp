class Solution {
public:
    int maxArea(vector<int>& height) {
        // 2 ptr approach
        int start = 0;
        int end = height.size()-1;
        int ans = INT_MIN;
        
        while(start < end){
            // to calc area --> smaller of ( h[start] or h[end] )* (end - start)
            ans = max(ans , min(height[start] , height[end]) * (end-start));
            
            // if the smaller one was start then increment start and vice versa
            if(height[start] < height[end]) start++;
            else end--;
        }
        
        return ans;
    }
};