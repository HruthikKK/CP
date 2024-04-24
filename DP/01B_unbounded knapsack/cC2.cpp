#include <bits/stdc++.h>
using namespace std;
#define pM 1000000007
#define ll 
 
// } Driver Code Ends
// User function Template for C++
 
 
vector<vector<int>> dp;
vector<ll int> wt;
vector<ll int> val;
 
int f(int i, int s){
    if(dp[i][s] != -1) return dp[i][s];
 
    int currA = 0;
    if(wt[i-1]<=s){
        int take = f(i,s-wt[i-1]);
        int noTake = f(i-1,s);
        if(take == -2 && noTake == -2){
            return dp[i][s] = -2;
        }
        else if(take == -2){
            return dp[i][s] = noTake;
        }
        else if(noTake == -2) return dp[i][s] = 1+take;
        else return dp[i][s] = min(take+1,noTake);
    }
    else{
        int noTake = f(i-1,s);
        return dp[i][s] = noTake;
    }
 
}
 
ll int knapSack(ll int N,ll int W, ll int VAL[])
{
    // code here
    wt.clear();
    wt.insert(wt.begin(),VAL,VAL+N);
    dp.clear();
    dp.resize(N+1,vector<ll int>(W+1,0));
 
    for(int i =0; i<=N; i++){
        for(int j =0; j<=W; j++){
            if(j == 0) dp[i][j] = 0;
            else if(i ==0) dp[i][j] = -2;
            else {
                int noTake = dp[i-1][j];
                int take = -2;
                if(wt[i-1]<=j) take = dp[i][j-wt[i-1]];
                if(take == -2 && noTake == -2){
                    dp[i][j] = -2;
                }
                else if(take == -2){
                    dp[i][j] = noTake;
                }
                else if(noTake == -2) dp[i][j] = 1+take;
                else dp[i][j] = min(take+1,noTake);
            }
        }
    }
 
    int ans = dp[N][W];
    // for(int i =0; i<=N; i++){
    //     for(int j =0; j<=W; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return ans;
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
        int ans = knapSack(N,W,val);
        if(ans == -2) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}