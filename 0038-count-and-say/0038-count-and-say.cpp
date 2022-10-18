class Solution {
public:
    string countAndSay(int n) {
       // base case 
       if(n == 1) return "1";
        
       string s = countAndSay(n-1);
       string ans = "";
       int count = 0;
       for(int i=0 ; i<s.length() ; i++){
           count++;
           // using the property of or i.e. if first
           // statement is true, it will execute the condition
           if(i == s.length()-1 or s[i] != s[i+1]){
               ans += to_string(count);
               ans += s[i];
               count = 0;
           }
       }
        
        return ans;
    }
};