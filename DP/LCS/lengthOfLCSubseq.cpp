#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 1000000007
#define all(v) v.begin(),v.end()

string a,b;
vector< vector< int> > dp(1007,vector<int>(1007));

int f( int i,  int j){

    if(dp[i][j] != -1) return dp[i][j];
    if(i>=a.size() || j>=b.size()) return dp[i][j] = 0;
    
    if(a[i] == b[j]){
        return dp[i][j] = 1+f(i+1,j+1);
    }
    else{
        int len = 0;
        len = max(len,f(i,j+1));
        len = max(len,f(i+1,j));
        // len = max(len,f(i+1,j+1));
        return dp[i][j] = len;
    }
}

//non_recursive
int f2(){
    vector<vector<int>> v(1007,vector<int>(1007));
    int m = a.size();
    int n = b.size();
    for(int i = m; i>=0; i--){
        for(int j = n; j>=0; j--){
            if(i == m || j == n){
                v[i][j] = 0;
            }
            else{
                if(a[i] == b[j]){
                    v[i][j] = 1 +v[i+1][j+1];
                }
                else{
                    v[i][j] = max(v[i+1][j],v[i][j+1]);
                }
            }
        }
    }

    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return v[0][0];
}
void solve(){

    cin>>a>>b;

    // ll int ans = f(0,0);
    ll int ans = f2();

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