#include <bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define ull unsigned long long
#define pp pair<ll int,ll int>
#define ci(n) cin>>n
#define co(n) cout<<n<<endl
#define primeM 998244353
#define all(v) v.begin(),v.end()

vector<ll int> v(1e5 + 7);
vector<ll int> dp(1e5 + 7);
ll int n,k;

ll int f(ll int cP){

    if(cP >= n-1 ) return 0;
    if(dp[cP] != -1 ) return dp[cP];

    ll int cA = LLONG_MAX;

    for(int i = 1; (i<=k) && ((cP+i) < n) ; i++){
        cA = min(cA,f(cP+i) + abs(v[cP+i] - v[cP]));
    }

    return dp[cP] = cA;
}
void solve(){

    cin>>n>>k;

    for(int i = 0; i<n; i++) cin>>v[i];
    for(int i = 0; i<n; i++) dp[i] = -1;

    ll int ans = LLONG_MAX;

    dp[n-1] = 0;
    for(int i = n-2; i>=0; i--){
        ll int cP = i;
        ll int cA = LLONG_MAX;
        for(int j = 1; j<=k && cP+j<n; j++){
            cA = min(cA,dp[cP+j]+abs(v[cP+j] - v[cP]));
        }
        dp[cP] = cA;
    }

    cout<<dp[0]<<endl;
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