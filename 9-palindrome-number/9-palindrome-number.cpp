class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
           return false;
        
        long temp = x;
        long rn = 0;
        long ld = 0;
        while(temp > 0){
            ld = temp % 10;
            rn = rn*10 + ld;
            temp /= 10;
        }
        
        if(rn == x)
            return true;
        
        return false;
    }
};