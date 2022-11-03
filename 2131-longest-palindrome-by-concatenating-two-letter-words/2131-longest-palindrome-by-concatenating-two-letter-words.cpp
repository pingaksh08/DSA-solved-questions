class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      // hashmap --> dry run for understanding
      int ans = 0;  
      unordered_map<string , int> mp;
      for(auto it : words){
          string rev = it;
          reverse(rev.begin() , rev.end());
          if(mp[rev] > 0){
              ans += 4;
              mp[rev]--;
          }
          
          else{
              mp[it]++;
          }
      }
        
      for(auto it : mp){
          if(it.first[0] == it.first[1] and it.second > 0)
              return ans + 2;
      }
        
        return ans;
    }
};