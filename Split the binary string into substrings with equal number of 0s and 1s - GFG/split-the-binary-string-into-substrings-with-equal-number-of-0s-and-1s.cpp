// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int c0=0 , c1=0 , count=0;
        for(int i=0 ; i<str.length() ; i++){
            if(str[i] == '0') c0++;
            if(str[i] == '1') c1++;
            if(c0 == c1) count++;
        }
        if(c0 != c1) return -1;
        return count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends