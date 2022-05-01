class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // using stack
       stack<char> st1, st2;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '#' and !st1.empty()) st1.pop();
            else if(s[i] != '#') st1.push(s[i]);
        }
       for(int i=0 ; i<t.length() ; i++){
            if(t[i] == '#' and !st2.empty()) st2.pop();
            else if(t[i] != '#') st2.push(t[i]);
        }
        
       if(st1 == st2) return true;
        
       return false; 
    }
};