//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long int> v(n+1);
        v[1] = 1;
        v[2] = 2;
        for(int i = 3; i<=n; i++){
            v[i] = (v[i-1])%(1000000007);
            v[i] += ((i-1) * v[i-2])%(1000000007);
        }
        
        return v[n]%(1000000007);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends