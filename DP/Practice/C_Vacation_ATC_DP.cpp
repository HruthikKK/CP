#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

vector<vector<int>> dp(100007,vector<int>(3));
vector<vector<int>> v(100007,vector<int>(3));

// ll int f(ll int i,ll int d){

//     if(dp[d][i] != -1) return dp[d][i];
//     ll int mxn = max(f((i+1)%3, d-1), f((i+2)%3, d-1));
//     // cout<<d<<" "<<i<<" "<<mxn<<endl;
//     return dp[d][i] = (v[d][i] + mxn);

// }
void solve(){

    ll int n;
    cin>>n;

    // dp[0][0] = 0;
    // dp[0][1] = 0;
    // dp[0][2] = 0;
    for(int i = 1; i<=n; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        // dp[i][0] = -1;
        // dp[i][1] = -1;
        // dp[i][2] = -1;
    }

    dp[n][0] = v[n][0];
    dp[n][1] = v[n][1];
    dp[n][2] = v[n][2];

    for(int i = n-1; i>=1; i--){
        dp[i][0] = v[i][0] + max(dp[i+1][1],dp[i+1][2]);
        dp[i][1] = v[i][1] + max(dp[i+1][0],dp[i+1][2]);
        dp[i][2] = v[i][2] + max(dp[i+1][1],dp[i+1][0]);
    }

    ll int ans = -1;

    ans = max(ans,dp[1][0]+0LL);
    ans = max(ans,dp[1][1]+0LL);
    ans = max(ans,dp[1][2]+0LL);

    // cout<<ans<<endl;
    // ans = max(ans,f(1,n));
    // cout<<ans<<endl;
    // ans = max(ans,f(2,n));

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

}