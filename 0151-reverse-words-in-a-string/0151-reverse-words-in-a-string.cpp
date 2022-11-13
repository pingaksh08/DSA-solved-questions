class Solution {
public:
    string reverseWords(string s) {
      int i=0 , n=s.size();
      vector<string> v;
      
      while(i<n){
          string curr = "";
          while(i<n and s[i] == ' ') i++;
          while(i<n and s[i] != ' ') curr += s[i++];
          
          if(curr == " " or curr == "") continue;
          v.push_back(curr);
      }
        
      string ans = v[0];
      for(int i=1 ; i<v.size() ; i++){
          ans = v[i] + " " + ans;
      }
        
      return ans;  
    }
};