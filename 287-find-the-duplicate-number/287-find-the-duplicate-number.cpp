class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_map<int , int> umap;
       for(int i=0 ; i<nums.size() ; i++) umap[nums[i]]++;
       
        int ans=0;
        for(auto it : umap){
            if(it.second >= 2){
                ans = it.first;
                break;
            }
        }
        
        return ans;
    }
};