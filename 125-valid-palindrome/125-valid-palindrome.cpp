class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0 ; i<s.length() ; i++){
            if((s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122) or (s[i] >= 48 and s[i] <= 57)){
                str.push_back(tolower(s[i]));
            }
        }
        string rev = string(str.rbegin(), str.rend());
        if(str == rev) return true;
        return false;
    }
};