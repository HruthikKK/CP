//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define pM 1000000007
#define ll 

// } Driver Code Ends
// User function Template for C++


vector<vector<int>> dp;
vector<ll int> wt;
vector<ll int> val;

ll int knapSack(ll int N,ll int W, ll int VAL[])
{
    // code here
    wt.clear();
    wt.insert(wt.begin(),VAL,VAL+N);
    dp.clear();
    dp.resize(N+1,vector<ll int>(W+1,0));

    //tabulation method
    // ------------------
    for(int i = 0; i<=N; i++){
        for(int j= 0; j<=W; j++){
            if(j==0) dp[i][j] = 1;
            else if(i ==0) dp[i][j] = 0;
            else{
                if(wt[i-1]<=j){
                    dp[i][j] = (dp[i-1][j] + dp[i][j - wt[i-1]])%pM;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    // ---------------------


    return dp[N][W];
}

//{ Driver Code Starts.

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        ll int val[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        cout<<knapSack(N,W,val);
    }
    return 0;
}