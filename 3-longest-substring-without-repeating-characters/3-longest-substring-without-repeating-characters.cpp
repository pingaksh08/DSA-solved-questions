class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        -- Sliding Window
        in map we store the right ptr value(s[right]) to its index,
        and we update the index with the latest appearance of the
        s[right] value and we move our left ptr to that index to 
        reduce the TC. Dry run on paper for better understanding. 
        */
       	int i = 0, j = 0;
		int n = s.length();
		map<char, int> mp;
		int ans = 0;

		while(j < n) {
			mp[s[j]]++;
			while(mp[s[j]] > 1 and i <= j) {
				mp[s[i]]--;
				i++;   
			}

			ans = max(ans, j-i+1);
			j++;
    }
    
        return ans;
    }
};