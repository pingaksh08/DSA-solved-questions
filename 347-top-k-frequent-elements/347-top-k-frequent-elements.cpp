class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        for(auto &it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            q.push({it.second,it.first});
        }
        while(k){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;
    }
};