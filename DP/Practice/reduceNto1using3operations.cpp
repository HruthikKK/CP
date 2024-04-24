#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

//given a number 'n' we hve to reduce n to 1 using any of the 3 op. at once
//  1. reduce n by 1, 2.if n is div by 2 reduce n = n/2, 3. if n is div by 3 reduce n=n/3
void solve(){

    ll int n;
    cin>>n;

    vector<ll int> v();

    if(n == 1){
        cout<<0<<endl;
        return;
    }
    else if(n<4){
        cout<<1<<endl;
        return;
    }

    v[1] = 0;
    v[2] = 1;
    v[3] = 1;

    for(int i= 4; i<=n; i++){
        ll int cA = 1 + v[i-1];
        if(i%2 == 0) cA = min(cA, 1 + v[i/2]);        
        if(i%3 == 0) cA = min(cA, 1 + v[i/3]);        
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