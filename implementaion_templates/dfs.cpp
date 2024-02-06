#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll int,ll int>
#define primeM 998244353
#define all(v) v.begin(),v.end()

// DFS graph
// ------------------------------------------------------------------------- //
vector<vector<ll int> > adj;
vector<bool> isV;
// ------------------------------------------------------------------------- //

void dfs(ll int i){
    if(isV[i]) return;

    isV[i] = true;

    for(int j = 0; j<adj[i].size(); j++){
        //kelsa
        dfs(adj[i][j]);
    }
}
void solve(){

    //n->nodes, m->edges
    ll int n,m;
    cin>>n>>m;

    adj.clear();
    adj.resize(n+1);
    isV.clear();
    isV.resize(n+1,false);

    // a, b vertices connected with a edge
    ll int a,b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        if(!isV[i]){
            //if ith vertex is not visited
        }
    }

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