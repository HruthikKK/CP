#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld long double
#define pp pair<ll int,ll int>
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
const ll int pM = 1e9+7;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// FUNCT------------------------------------------------------------------------- /

//Binary search
ll int findInVL(vector<ll int>& v,ll int x){
    if(v.empty()) return -1;
    ll int l = 0;
    ll int h = v.size()-1;
    int idx = -1;
    while(l<=h){
        ll int m = (l+h)/2;
        if(v[m] == x){
            h = m-1;
        }
        else if(v[m]<x){
            idx = m; 
            l = m+1;
        }
        else h = m-1;
    }
    return idx;
}

ll int findInVH(vector<ll int>& v,ll int x){
    if(v.empty()) return v.size();

    ll int l = 0;
    ll int h = v.size()-1;
    ll int idx = v.size();
    while(l<=h){
        ll int m = (l+h)/2;
        if(v[m] == x) l = m+1;
        else if(v[m]<x) l = m+1;
        else{
            idx = m;
            h = m-1;
        }
    }
    return idx;
}

static bool sortbyCond(const vector<ll int>& a,const vector<ll int>& b){
    return a[1]>b[1];
}

// ------------------------------------------------------------------------- //

// GLOBAL VAR------------------------------------------------------------------------- //

// ------------------------------------------------------------------------- //


void solve(){

    ll int n;
    cin>>n;
    vector<ll int> v(n);
    for(int i =0; i<n; i++) cin>>v[i];
    sort(all(v));

    for(auto x : v) cout<<x<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("ip.txt","r",stdin);
        freopen("op.txt","w",stdout);
        freopen("err.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll int t = 1;
    cin>>t;
    
    while(t--){
        solve();
    }

} 