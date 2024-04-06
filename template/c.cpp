#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<string,ll int>
#define all(v) v.begin(),v.end()
const ll int pM = 998244353;

// FUNCT------------------------------------------------------------------------- /

void dispV(vector<ll int>& v){
    for(int i =0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}
void dispV(vector<int>& v){
    for(int i =0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}
void dispM(map<ll int,ll int>& m){
    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
}

//Binary search
ll int findInVL(vector<ll int>& v,ll int x){
    if(v.empty()) return -1;
    ll int l = 0;
    ll int h = v.size()-1;
    while(l<=h){
        ll int m = (l+h)/2;
        if(v[m] == x) return m;
        else if(v[m]<x) l = m+1;
        else h = m-1;
    }
    return h;
}

ll int findInVH(vector<ll int>& v,ll int x){
    if(v.empty()) return v.size();

    ll int l = 0;
    ll int h = v.size()-1;
    while(l<=h){
        ll int m = (l+h)/2;
        if(v[m] == x) return m;
        else if(v[m]<x) l = m+1;
        else h = m-1;
    }
    return l;
}

static bool sortbyCond(const vector<ll int>& a,const vector<ll int>& b){
    if(a[0] == b[0]) return b[1]<a[1];
    return a[0]<b[0];
}

// ------------------------------------------------------------------------- //

// GLOBAL VAR------------------------------------------------------------------------- //

// set<ll int> s;
// ll int n;
// vector<ll int> ans;
// vector<vector<ll int>> v;
// vector<ll int> p;
// vector<int> vis;
// vector<ll int> a;

// ------------------------------------------------------------------------- //

void solve(){

    // string s;
    // getline(cin,s);

    // stringstream str(s);

    // ll int ans =0;
    // string cS;
    // while(str >> cS){
    //     ll int sz = cS.size();
    //     if(sz%2 == 0 && sz>ans) ans = sz;
    // }

    // cout<<ans<<endl;
// --------------------------------------------

    // vector<vector<ll int>> v;
    // v.push_back({1,2});
    // v.push_back({1,3});
    // v.push_back({0,2});
    // v.push_back({0,1});

    // sort(v.begin(),v.end(),sortbyCond);
    // for(int i = 0; i<4; i++) dispV(v[i]);

//----------------------------------------------------

    // priority_queue<ll int,vector<ll int>, greater<ll int>> p;
    // p.push(3);
    // p.push(2);
    // p.push(1);

    // while(!p.empty()){
    //     cout<<p.top()<<endl;
    //     p.pop();
    // }
    // cout<<endl;

//------------------------------------------------------

}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("ip.txt","r",stdin);
        freopen("op.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

} 