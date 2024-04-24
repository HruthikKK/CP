#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()
const ll mx = 2007;

vector<ll int> a(mx);
vector<ll int> b(mx);
ll int n,m;
ll int k;
ll int dp [2007][2007][7];
ll int f(ll int i, ll int j, int tk){

    // cout<<i<<" "<<j<<" "<<tk<<endl;
    if(i == m || j == n) return dp[i][j][tk] = 0;
    if(dp[i][j][tk] != -1) return dp[i][j][tk];

    if(a[i] == b[j]){
        // cout<<i<<" "<<j<<" equal"<<endl;
        
        // cout<<dp[i][j][tk]<<endl;
        return dp[i][j][tk] = (1 + f(i+1,j+1,tk));;
    }
    else{
        if(tk) {dp[i][j][tk] = 1 + f(i+1,j+1,tk-1);}
        // dp[i][j][tk] = max(dp[i][j][tk],f(i+1,j+1,tk));
        dp[i][j][tk] = max(dp[i][j][tk],f(i+1,j,tk));
        dp[i][j][tk] = max(dp[i][j][tk],f(i,j+1,tk));
        return dp[i][j][tk];
    }
}
void solve(){
    cin>>m>>n;
    cin>>k;
    for(int i = 0; i<m; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int h = 0; h<=k; h++) dp[i][j][h] = -1;
        }
    }

    ll int ans2 = f(0,0,k);
    ll int ans = dp[0][0][k];
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