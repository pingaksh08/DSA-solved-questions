class Solution {
public:
    string countAndSay(int n) {
        // base case
        if(n == 1)
            return "1";
        
        // recursion
        string str = countAndSay(n-1);
        // its actually the pair of frequency and element i.e. 111 22 3 --> 31 22 13
        string ans = "";
        int count = 0;
        for(int i=0 ; i<str.length() ; i++){
            count++;
            /*
            using property of || operator to avoid error i.e.
            if first statement return true it will not check further statements
            and will return true so it will execute well till the last iteration.
            */
            if(i == str.length()-1 or str[i] != str[i+1]){
                ans += to_string(count);
                ans += str[i];
                count = 0;
            }
        }
        
        return ans;
    }
};