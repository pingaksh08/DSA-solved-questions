class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for(auto it : arr) mp[it]++;
        
        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);
        
        int sum=0 , count=0;
        while(!pq.empty() and sum < arr.size()/2){
            sum += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};