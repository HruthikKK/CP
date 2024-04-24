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
#define pp pair<int,int>

int f(vector<int>& wt,vector<int>& val,int i,int currW){
    if(i == -1 || currW == 0){
        return 0;
    }

    if(wt[i]<=currW){
        return max((val[i]+f(wt,val,i-1,currW-wt[i])),(f(wt,val,i-1,currW)));
    }
    else return f(wt,val,i-1,currW);
}

void solve(){

    int n,W;
    cin>>n>>W;

    vector<int> wt(n);
    vector<int> val(n);
    for(int i = 0; i<n; i++) cin>>wt[i];
    for(int i = 0; i<n; i++) cin>>val[i];

    ll int ans = f(wt,val,n-1,W);
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