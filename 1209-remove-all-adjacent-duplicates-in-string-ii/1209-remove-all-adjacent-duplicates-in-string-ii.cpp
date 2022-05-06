class Solution {
public:
    string removeDuplicates(string s, int k) {
        /*
        --> use stack(st).
        --> maintain a freq vector which will keep track of 
            continious occourences of the elements
        --> push each character in stack while maintaining the
            freq vector
        --> if at any point freq[st.top()] == k, pop from stack k times
        --> then store the remaining char of stack in a string 
            and reverse it and return
        */
        
        stack<int> st;
        vector<int> freq(s.length() , 1);
        string ans;
        st.push(0);
        
        for(int i=1 ; i<s.length() ; i++){
            if(!st.empty()){
                if(s[st.top()] == s[i])
                    freq[i] = freq[st.top()] + 1;
            }
            
            st.push(i);
            
            if(freq[st.top()] == k){
                for(int i=0 ; i<k ; i++)
                    st.pop();
            }
        }
        
        while(!st.empty()){
            ans += s[st.top()];
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};