//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<int> v;
    vector<vector<int>> dp;
    int f(int i,int cL){
        if(dp[i][cL]!=-1) return dp[i][cL];

        if(i<=cL){
            return dp[i][cL] = max(f(i-1,cL), v[i-1]+f(i,cL - i));
        }
        else return dp[i][cL] = f(i-1,cL);
    }
    int cutRod(int price[], int n) {
        //insteading of trying to cutt the rod try to pick rods of smaller size to build the bigger rod of length n
        v.clear();
        for(int i = 0; i<n; i++) v.push_back(price[i]);
        dp.clear();
        dp.resize(n+1,vector<int> (n+1,-1));
        //give importance to initialization
        for(int i =0; i<=n; i++) dp[i][0] = 0;
        for(int j =1; j<=n; j++) dp[0][j] = v[j-1];
        // for(int i = 0; i<=n; i++){
        //     for(int j =0; j<=n; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        // int ans = f(n,n);
        for(int i =0; i<=n; i++){
            for(int j =0; j<=n; j++){
                if(j ==0) dp[i][j] = 0;
                else if(i == 0) dp[i][j] = v[j-1];
                else{
                    if(i<=j) dp[i][j] = max(dp[i-1][j],v[i-1]+dp[i][j-i]);   
                    else dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        // for(int i = 0; i<=n; i++){
        //     for(int j =0; j<=n; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<dp[n][n]<<endl; 
        return dp[n][n];   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends