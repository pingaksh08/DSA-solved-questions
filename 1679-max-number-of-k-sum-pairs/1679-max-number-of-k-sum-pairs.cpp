class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int count = 0;
        
        for(auto it: nums){
            if(umap[k-it] > 0){
                count++; 
                umap[k-it]--;
            }
             else umap[it]++;
        }
        
        return count;
    }
};