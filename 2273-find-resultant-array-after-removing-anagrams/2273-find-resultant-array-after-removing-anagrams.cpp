class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string cmp = words[0];
        ans.push_back(cmp);
        sort(cmp.begin() , cmp.end());
        
        for(int i=1 ; i<words.size() ; i++){
            string curr = words[i];
            sort(curr.begin() , curr.end());
            if(cmp == curr) continue;
            else{
                ans.push_back(words[i]);
                cmp = curr;
            }
        }
        
        return ans;
    }
};