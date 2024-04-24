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

vector<int> wt;
vector<int> val;
vector<vector<int>> t;

int f(int i,int currW){

    if(i == -1 || currW == 0){
        return 0;
    }

    if(t[i][currW] != -1) {return t[i][currW];}

    if(wt[i]<=currW){
        int a1 = val[i]+f(i-1,currW-wt[i]);
        int a2 = f(i- 1,currW);
        return t[i][currW] = max(a1,a2); 
    }
    else return f(i-1,currW);
}

//top down

int f2(int n,int W){
    
    for(int i = 0; i<=n; i++){
        for(int j =0; j<=W; j++){
            if(!i || !j) t[i][j] = 0;
            else{
                if(wt[i-1]<=j){
                    t[i][j] = max(wt[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }

    // for(int i = 0; i<=n; i++){
    //     for(int j =0; j<=W; j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[n][W];
}

void solve(){

    int n,W;
    cin>>n>>W;

    wt.resize(n);
    val.resize(n);

    t.clear();
    t.resize(n+1,vector<int>(W+1));
    for(int i = 0; i<=n; i++){
        for(int j =0; j<=W; j++){
            t[i][j] = -1;
        }
    }

    for(int i = 0; i<n; i++) cin>>wt[i];
    for(int i = 0; i<n; i++) cin>>val[i];

    ll int ans = f(n-1,W);
    cout<<ans<<endl;

    t.clear();
    t.resize(n+1,vector<int>(W+1));
    for(int i = 0; i<=n; i++){
        for(int j =0; j<=W; j++){
            t[i][j] = -1;
        }
    }

    ll int ans2 = f2(n,W);
    cout<<ans2<<endl;
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