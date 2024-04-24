#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

void solve(){

     ll int n;
    cin>>n;

    vector<ll int> v(1e6+7);

    if(n<10){
        cout<<1<<endl;
        return;
    }
    for(int i = 1; i<10; i++) v[i] = 1;

    for(int i = 10; i<=n; i++){
        ll int ti = i;
        ll int cA = INT_MAX;
        while(ti){
            ll int r = ti%10;
            if(r){
                cA = min(cA,1+v[i-r]);
            }
            ti/=10;
        }
        v[i] = cA;
    }

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