#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

ll int a, b;
vector<int> pos(1000007);
// vector<vector<int>> dp(2,vector<int>(1000007));
// //1Row - even cases Aasin->Boyan
// //2R - odd cases Boyan->Aasin

// bool f(ll int cTw, bool isE){
//     if(dp[!isE][cTw] != -1) return dp[!isE][cTw];
//     if(isE){
//         // if(!cTw) return 1;//a wins
//         // else{
//             bool flag = true;
//             flag = f(cTw-1,!isE);
//             if(!flag) return dp[0][cTw] = 0;
//             if(a<=cTw) flag = f(cTw - a,!isE);
//             if(!flag) return dp[0][cTw] = 0;
//             if(b<=cTw) flag = f(cTw - b,!isE);
//             if(!flag) return dp[0][cTw] = 0;
//             return dp[0][cTw] = 1;
//         // }
//     }
//     else{
//         // if(!cTw) return 0;
//         // else{
//             bool flag = false;
//             flag = f(cTw-1,!isE);
//             if(flag) return dp[1][cTw] = 1;
//             if(a<=cTw) flag = f(cTw - a,!isE);
//             if(flag) return dp[1][cTw] = 1;
//             if(b<=cTw) flag = f(cTw - b,!isE);
//             if(flag) return dp[1][cTw] = 1;
//             return dp[1][cTw] = 0;
//         // }
//     }
// }
void solve(){

    ll int n;
    cin>>a>>b>>n;

    string ans = "";
    
    vector<ll int> twH(n);
    for(int i = 0; i<n; i++) cin>>twH[i];
    ll int mxTw = *max_element(all(twH));
    // dp[0][0] = 1;
    // dp[1][0] = 0;
    for(int j = 1; j<=mxTw; j++){
       pos[j] = -1;
    }
    // pos[0] = 1;
    pos[1] = 1;
    pos[a] = 1;
    pos[b] = 1;
    for(int i = 2; i<=mxTw ;i++){
        if(i == a || i == b) continue;
        if(pos[i-1] == 0){
            pos[i] = 1;
        } 
        else if(a<=i){
            if(pos[i-a] == 0) pos[i] = 1;
            else if(b<=i){
                if(pos[i-b] == 0) pos[i] = 1;
                else pos[i] = 0;
            }
            else pos[i] = 0;
        }
        else pos[i] = 0;
    }

    // for(int i = 0; i<=mxTw; i++) cout<<pos[i]<<" ";
    // cout<<endl;

    for(int i = 0; i<n; i++){
        // ll int tw = 0;
        // cin>>tw;
        if(pos[twH[i]]) ans += "A";
        else ans += "B";
    }

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