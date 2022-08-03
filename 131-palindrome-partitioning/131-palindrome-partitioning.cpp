class Solution {
public:

    vector<vector<string>> ans;
    vector<string> str;
    
    bool ispalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++; end--;
        }
        return true;
    }
    
    void solve(int index, string s){
        if(index == s.length()){
            ans.push_back(str);
            return;
        }
        
        for(int i=index ; i<s.length() ; i++){
            if(ispalindrome(s, index, i)){
                str.push_back(s.substr(index, i-index+1));
                solve(i+1, s);
                str.pop_back();
            }
        }
    }
     
    vector<vector<string>> partition(string s) {
      solve(0,s);
      return ans;  
    }
};