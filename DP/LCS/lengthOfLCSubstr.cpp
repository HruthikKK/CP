#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 1000000007
#define all(v) v.begin(),v.end()

string a,b;
ll int m,n;
vector< vector< int> > dp;

void f(int i,int j){

    if(i == m || j == n){
        dp[i][j] = 0;
        return;
    }
    if(dp[i][j] != -1) return;

    if(a[i] == b[j]){
        f(i+1,j+1);
        dp[i][j] = 1 + dp[i+1][j+1];
    }
    else{
        dp[i][j] = 0;
    }
    f(i+1,j);
    f(i,j+1);
    
}

//non_recursive
int f2(){
    vector<vector<int>> v(m+7,vector<int>(n+7));
    int m = a.size();
    int n = b.size();
    for(int i = m-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(a[i] == b[j]){
                v[i][j] = 1+v[i+1][j+1];
            }
        }
    }
    int ans =0;
    for(int i = m-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            ans = max(ans,v[i][j]);
        }
    }
    return ans;

}
void solve(){

    cin>>a>>b;
    m = a.size();
    n = b.size();
    dp.resize(m+7,vector<int>(n+7,-1));
    // f(0,0);

    int ans =0;
    // for(int i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         ans = max(ans,dp[i][j]);
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ans = f2();

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