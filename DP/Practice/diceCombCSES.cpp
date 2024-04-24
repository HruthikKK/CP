#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 1000000007
#define all(v) v.begin(),v.end()

void solve(){

    ll int n;
    cin>>n;

    vector<ll int> v(n+1);

    ll int st= 0;
    for(int i = 1; i<7 && i<=n; i++){
        v[i] = 1 + st;
        st += v[i];
    }

    if(n<7){
        cout<<v[n]<<endl;
        return;
    }

    for(int i = 7; i<=n; i++){
        ll int cS = 0;
        for(int k = 1; k<=6; k++){
            cS += v[i-k];
            cS %= primeM;
        }
        v[i] = cS;
    }

    // for(int i = 0; i<=n; i++) cout<<v[i]<<" ";
    // cout<<endl;

    v[n] %= primeM;
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