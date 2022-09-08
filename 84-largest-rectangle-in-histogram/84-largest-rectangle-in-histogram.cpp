class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      stack<int> st;
      int NSL[n] , NSR[n];
      // next smaller element to left
        for(int i=0 ; i<n ; i++){
            while(!st.empty() and heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                NSL[i] = 0;
            }
            
            else{
                // +1 as we need till the next element as NSL will not be a part of ans
                NSL[i] = st.top() + 1;  
            }
            // we need index only for the width
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        // next smaller element to right
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() and heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                NSR[i] = n-1;
            }
            
            else{
                // -1 as we need till the prev element as NSR will not be a part of ans
                NSR[i] = st.top() - 1;
            }
            
            st.push(i);
        }
        
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            ans = max(ans, (NSR[i] - NSL[i] + 1) * heights[i]);
        }
        
        return ans;
    }
};