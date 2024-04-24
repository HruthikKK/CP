//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int n,s;
    vector<vector<int>> dp;
    vector<int> v;
    int f(int i,int s){
        if(dp[i][s] != -1) return dp[i][s];
        
        if(v[i-1]<=s){
            return dp[i][s] = (f(i-1,s-v[i-1]) || f(i-1,s));
        }
        else return dp[i][s] = f(i-1,s);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        n=arr.size();
        s = sum;
        v = arr;
        dp.resize(n+1,vector<int>(s+1));
        for(int i = 0; i<=n; i++){
            for(int j =0; j<=s; j++){
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else dp[i][j] = -1;
            }
        }
        int ans = f(n,s);
        // for(int i =0; i<=n; i++){
        //     for(int j =0; j<=s; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends