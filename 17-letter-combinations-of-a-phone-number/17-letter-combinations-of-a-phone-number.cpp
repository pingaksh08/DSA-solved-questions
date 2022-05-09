class Solution {
public:
    vector<string> v;
    map<char,string> m;
    
    void solve(string digits , int index , string s)
    {
        if(index == digits.size())
        {
            v.push_back(s);
            return;
        }
        for(auto it : m[digits[index]])
        {
            s.push_back(it);
            solve(digits , index+1 , s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        if(digits.size() == 0)
        {
            return {};
        }
        
        string str = "";
        solve(digits , 0 , str);
        return v;
    }
};