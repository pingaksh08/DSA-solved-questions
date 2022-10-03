class Solution {
public:
    string multiply(string num1, string num2) {
        // edge cases
        if(num1 == "0" or num2 == "0")
            return "0";
        
        int n1 = num1.length() , n2 = num2.length();
        vector<int> v(n1 + n2 , 0); // max size of the product
        
        // implementing basic arithmetic multiplication
        for(int i=n1-1 ; i>=0 ; i--){
            for(int j=n2-1 ; j>=0 ; j--){
                v[i+j+1] += (num1[i] - '0') * (num2[j] - '0'); // last digit
                v[i+j] += v[i+j+1] / 10; // adding carry to next
                v[i+j+1] %= 10; // last digit's one's place
            }
        }
        
        int i=0;
        while(i<v.size() and v[i] == 0) i++;
        
        string ans = "";
        while(i<v.size()){
            ans.push_back(v[i++] + '0');
        }
        
        return ans;
    }
};