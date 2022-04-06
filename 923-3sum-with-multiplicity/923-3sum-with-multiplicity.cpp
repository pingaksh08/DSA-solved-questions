class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
       // a + b + c = x
       // a + b = x - c
       //  we store the sum (a + b) in map and check for val(x - c)
       //if found, add it to ans 
        unordered_map<int, int> umap;
        int count = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < arr.size(); i++) {
            count = (count + umap[target - arr[i]]) % mod;
            
            for (int j = 0; j < i; j++) {
                umap[arr[i] + arr[j]]++;
            }
        }
        return count;
    }
};