class Solution {
public:
    int longestPalindrome(string s) {
       sort(s.begin() , s.end());
       int ans = 0;
       for(int i=1 ; i<s.length() ; i++){
           if(s[i] == s[i-1]){
               ans += 2;
               i++;
           }  
       }
        
        if(ans < s.length()) return ans+1;
        return ans;
    }
};