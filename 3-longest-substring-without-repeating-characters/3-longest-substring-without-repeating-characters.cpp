class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
       int left=0 , right=0;
       unordered_map<char, int> freq;
       int ans = 0; 
       
       while(right < n){
           
           if(freq[s[right]] == 0){
               freq[s[right]]++;
          
           }
           else{
               while(s[left] != s[right]){
                   freq[s[left]]--;
                   left++;
               }
         
              left++; 
           }
           
           ans = max(ans, right - left + 1);
      
           right++;
       }
        
        return ans;
        
    }
};

