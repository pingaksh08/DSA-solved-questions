class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int curr = 0;
        bool flag = false; // to keep track of direction
        for (char ch : s)
        {
            rows[curr] += ch;
            // edge conditions to flip the boolean
            if (curr == 0 || curr == numRows - 1)
            {
                flag = !flag;
            }
            // moving up or down as per the flag
            curr += flag ? 1 : -1;
        }
        
        string ans;
        for (string row : rows)
        {
            ans += row;
        }
        return ans;
    }
};