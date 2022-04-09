class Solution {
public:
    int twoEggDrop(int n) {
       vector<int> dp;
        int k=1;
        while(k != 100){
            for(int i=0 ; i<k ; i++){
                dp.push_back(k);
            }
            k++;
        }
        
        return dp[n-1];
    }
};