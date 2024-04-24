#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

void solve(){

    ll int n,x;
    cin>>x>>n;

    vector<ll int> v(n+7);
    vector<int> c(x);
    for(int i = 0; i<x; i++) cin>>c[i];

    sort(all(c));

    if(n<c[0]){
        cout<<-1<<endl;
        return;
    }

    v[0] = 0; 
    for(int i = 1; i<c[0]; i++) v[i] = -1;

    for(int i = c[0]; i<=n; i++){
        ll int ti = i;
        ll int cA = INT_MAX;
        for(int j = 0; j<x && c[j]<=ti; j++){
            ll int cA2 = v[ti - c[j]];
            if(cA2 != -1){
                cA = min(cA,cA2);
            }
        }
        if(cA == INT_MAX){
            v[i] = -1;
        }
        else{
            v[i] = 1+cA;
        }
    }

    // for(int i = 0; i<=n; i++) cout<<v[i]<<" ";
    // cout<<endl;
   
    cout<<v[n]<<endl;
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