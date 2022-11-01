class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      unordered_map<string , vector<string>> mp;
      /*
       map will store like --
        aet --> eat , tea , ate
        abt --> bat
        ant --> nat , tan
      */  
       for(int i=0 ; i<strs.size() ; i++){
           string st = strs[i];
           sort(strs[i].begin() , strs[i].end());
           mp[strs[i]].push_back(st);
       }
        
       for(auto it : mp){
           ans.push_back(it.second);
       }
        
       return ans; 
    }
};