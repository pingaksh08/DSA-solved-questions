class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0 , count2 = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(i <= (s.length()/2) - 1){
                if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' ) count1++;
            }
            
            else{
                if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' ) count2++;
            }
        }
        // cout << count1 << " " << count2 << endl;
        return count1==count2;
    }
};