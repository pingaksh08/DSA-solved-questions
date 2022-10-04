class Solution {
public:
    // 1D dp
    int solve(string s , vector<int> &dp){
        int n = s.length();
        
        // base cases
        if(n == 0) return 1;
        else if(s[0] == '0') return 0;
        
        // return if solution exists
        if(dp[n] != -1) return dp[n];
        
        int op1 = 0 , op2 = 0;
        // op1 for all single characters
        op1 = solve(s.substr(1) , dp);
        
        // op2 for all double chars but only within the range 0 - 26
        if((n>1) and (s[0] == '1' or (s[0] == '2' and s[1] <= '6'))){
            op2 = solve(s.substr(2) , dp);
        }
        
        return dp[n] = op1 + op2;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length()+1 , -1);
        return solve(s, dp);
    }
};