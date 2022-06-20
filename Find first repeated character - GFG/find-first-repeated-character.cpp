// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s)
{
    map<char , int> m;
    string ans = "";
    for(int i=0 ; i<s.length() ; i++){
        m[s[i]]++;
        if(m[s[i]] > 1){
            ans = s[i];
            return ans;
        }
    }
    
    return "-1";
 
}