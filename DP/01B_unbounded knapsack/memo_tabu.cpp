//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    vector<int> wt;
    vector<int> val;
    int knapSack(int N, int W, int VAL[], int WT[])
    {
        // code here
        wt.clear();
        wt.insert(wt.begin(),WT,WT+N);
        val.clear();
        val.insert(val.begin(),VAL,VAL+N);
        dp.clear();
        dp.resize(N+1,vector<int>(W+1,-1));
        for(int i =0; i<=N; i++) dp[i][0] = 0;
        for(int i =0; i<=W; i++) dp[0][i] = 0;

        //tabulation method
        // ------------------
        // for(int i = 0; i<=N; i++){
        //     for(int j= 0; j<=W; j++){
        //         if(!j || !i) dp[i][j] = 0;
        //         else{
        //             int t = 0;
        //             while(t*wt[i-1]<=j){
        //                 dp[i][j] = max(dp[i][j],(t*val[i-1]) + dp[i-1][j-(t*wt[i-1])]);
        //                 t++;
        //             }
        //         }
        //     }
        // }
        // ---------------------

        //memoization
        int ans =  f(N,W);
        // for(int i = 0; i<=N; i++){
        //     for(int j = 0; j<=W; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
    int f(int i,int currW){
    
        if(dp[i][currW]!=-1) return dp[i][currW];
        
        if(wt[i-1]<=currW) return dp[i][currW] = max((val[i-1] + f(i,currW-wt[i-1])),f(i-1,currW));
        else return dp[i][currW] = f(i-1,currW);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends