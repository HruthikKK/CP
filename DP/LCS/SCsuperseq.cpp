// Try It once
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 1000000007
#define all(v) v.begin(),v.end()

string a,b;
// vector< vector< int> > dp(1007,vector<int>(1007));

//non_recursive
string f2(){
    int m = a.size();
    int n = b.size();
    vector<vector<int>> v(m+7,vector<int>(n+7));
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

    // for(int i = 0; i<=m; i++){
    //     for(int j = 0; j<=n; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    string lcs = "";
    ll int i = 0,j =0;
    while(i<m && j<n){
        if(a[i] == b[j]){
            lcs += a[i];
            i++;
            j++;
        }
        else{
            if(v[i+1][j]>v[i][j+1]) i++;
            else j++;
        }
    }

    if(lcs.size() == 0) return a+b;//concat of both string

    string sSS = "";
    i = 0;j = 0;
    ll int k = 0;
    while(k<lcs.size()){
        while(a[i] != lcs[k]){
            sSS += a[i];
            i++;
        }
        while(b[j] != lcs[k]){
            sSS += b[j];
            j++;
        }
        sSS += lcs[k];
        i++;
        j++;
        k++;
    }

    while(i<m){
        sSS += a[i];
        i++;
    }

    while(j<n){
        sSS += b[j];
        j++;
    }

    // cout<<sSS<<endl;

    return sSS;
}
void solve(){

    cin>>a>>b;

    // ll int ans = f(0,0);
    string ans = f2();

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