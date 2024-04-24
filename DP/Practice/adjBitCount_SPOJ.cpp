#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

ll int dp[107][107][2];

ll int f(ll int cB, ll int cK, bool isBO){

    // if(!cB){
    //     if(cK) return dp[cB][cK][isBO] = 0;
    //     else return dp[cB][cK][isBO] = 1;
    // }

    if(dp[cB][cK][isBO] != -1) return dp[cB][cK][isBO];

    if(isBO){
        ll int cA = 0;
        cA += f(cB-1,cK,0);
        if(cK) cA += f(cB-1,cK-1,1);
        return dp[cB][cK][isBO] =  cA;
    }
    else{
        ll int cA =0;
        cA += f(cB-1,cK,0);
        cA += f(cB-1,cK,1);
        return dp[cB][cK][isBO] = cA;
    }
}
void solve(){

    ll int tc;
    cin>>tc;

    ll int n,k;
    cin>>n>>k;

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=k; j++){
            dp[i][j][0] = (ll)(-1);
            dp[i][j][1] = (ll)(-1);
        }
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    ll int ans = f(n,k,0);
    cout<<tc<<" "<<ans<<endl;    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

}