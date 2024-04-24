#include <bits/stdc++.h>
using namespace std;
#define ll long long    
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

// approach is quite clear: greedy + dp
// if at any day we can buy to sell it at greater price we will take chance to maximise profit
// we see all possible days where we can sell by making profit from current day
ll int tk;
vector<int> v(1007);
vector<vector<int>> grIdx(1007);
vector<vector<int>> dp(1007,vector<int>(107));
ll int n;

int f(ll int i, ll int ck){

    if(i == n || (!ck)) return dp[i][ck] = 0;
    if(dp[i][ck] != -1) return dp[i][ck];

    ll int sz = grIdx[i].size();
    
    dp[i][ck] = f(i+1,ck);
    for(int j = 0; j<sz; j++){
        dp[i][ck] = max(dp[i][ck],(v[grIdx[i][j]] - v[i]+f(grIdx[i][j]+1,ck-1)));
    }
    return dp[i][ck];
}

int maxProfit(int k, vector<int>& prices) {
    
    tk = k;
    n = prices.size();
    for(int i = 0; i<n; i++) v[i] = prices[i];

    //grIdx vector
    vector<int> temp;
    temp.push_back(n-1);
    ll int sz = 1;
    for(int i = n-2; i>=0; i--){
        if(sz){
            while(sz && v[temp[sz-1]]<=v[i]){
                temp.pop_back();
                sz--;
            }
            grIdx[i] = temp;
        }
        temp.push_back(i);
        sz++;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=k; j++) dp[i][j] = -1;
    }
    int ans = f(0,k);
    cout<<ans<<endl;
    return ans;

}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i= 0; i<n; i++){
        cin>>v[i];
    }
    maxProfit(k,v);
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