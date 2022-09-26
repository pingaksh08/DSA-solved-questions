class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      if(s.length() == 1){
          return false;
      } 
      for(int i=0 ; i<s.length() ; i++){
          if(s[i] == '(' or s[i] == '{' or s[i] == '['){
              st.push(s[i]);
          }
          else if(!st.empty()){
              int top = st.top();
              st.pop();
              if((s[i] == ')' and top != '(') or (s[i] == '}' and top != '{') or (s[i] == ']' and top != '[')){
                  return false;
              }
          }
          
          else 
              return false;
      }
        
        if(!st.empty())
            return false;
        
        return true;
    }
};