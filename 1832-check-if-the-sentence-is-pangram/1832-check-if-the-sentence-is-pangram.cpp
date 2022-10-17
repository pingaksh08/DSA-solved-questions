class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char> st; 
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == ' ') continue;
            st.insert(s[i]);
        }
        if(st.size() < 26) return false;
        
        return true;
    }
};