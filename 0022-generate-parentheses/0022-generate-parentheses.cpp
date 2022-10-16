class Solution {
public:
//     bool isvalid(string s){
//         stack<char> st;
//         for(int i=0 ; i<s.length() ; i++){
//             if(s[i] == '('){
//                 st.push(s[i]);
//             }
//             else if(!st.empty()){
//                 auto top = st.top();
//                 st.pop();
                
//                 if(top == '(' and s[i] != ')')
//                     return false;
//             }
//             else
//                 return false;
//         }
        
//         if(st.size())
//             return false;
        
//         return true;
//     }
    vector<string> ans;
    void solve(int countopen , int countclose , string s , int n){
       // base case
       //when open bracket count == n, we push the close brackets 
        if(countopen == n){
            while(countclose < n){
                s += ')';
                countclose++;
            }
            ans.push_back(s);
            return;
        }
        // pushing opening bracket
        solve(countopen + 1 , countclose , s + '(' , n);
        // pushing close only makes sense when opencount > closecount 
        if(countclose < countopen){
            solve(countopen , countclose + 1 , s + ')' , n);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
       string s = "";
       solve(0 , 0 , s , n);
       return ans; 
    }
};