#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld long double
#define pp pair<ll int,ll int>
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
const ll int MOD = 1e9+7;


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
            return m;
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
        if(v[m] == x){
            return m;
        }
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

ll power(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = ((res % m) * (a % m)) % m;
        b = b >> 1;
        a = ((a % m) * (a % m)) % m;
    }
    return res % m;
}
ll add(ll a, ll b, ll m = MOD)
{
    return ((a % m) + (b % m)) % m;
}
ll sub(ll a, ll b, ll m = MOD)
{
    return ((a + m) % m - (b + m) % m) % m;
}
ll mul(ll a, ll b, ll m = MOD)
{
    return ((a % m) * (b % m)) % m;
}

// ------------------------------------------------------------------------- //

// GLOBAL VAR------------------------------------------------------------------------- //

vector<ll int> pn;

// ------------------------------------------------------------------------- //

void solve(){
    
    ll int n;
    cin>>n;

    ll int ans = -1;

    ll int l = 0, h = INT_MAX;
    vector<ll int> dig;
    ll int m = 1;
    while(l<=h){
        m = (l+h)/2;
        debug(m)
        dig.clear();
        ll int tm = m;
        ll int nk = 0;
        while(tm){
            dig.push_back(tm%10);
            tm /= 10;
            // debug(tm)
        }
        reverse(all(dig));
        // debug(dig)
        vector<ll int> kdig = dig;
        kdig[dig.size()-1] = dig[dig.size()-1]+1;
        for(int i = dig.size()-2; i>=0; i--){
            kdig[i] = (kdig[i]+1)*kdig[i+1];
            // debug(kdig[i])
        }
        // debug(dig)
        ll int prevDig = 0;
        ll int bdig = dig.size()-1;
        for(int i = 0; i<dig.size(); i++){
            // debug(i)
            if(dig[i]>4){
                nk += (prevDig+1)*(pn[bdig]);
            }
            else if(dig[i]<4) nk += prevDig*pn[bdig];
            else{
                nk += prevDig*pn[bdig];
                if(i != dig.size()-1) nk += kdig[i+1];
            }
            bdig--;
            prevDig = prevDig*10+dig[i];
            // debug(nk)
            // debug(bdig)
            // debug(prevDig)
        }

        // debug(n)
        // debug(m-nk)
        if(m-nk == n){
            // debug(m)
            cout<<m<<endl;
            return;
        }
        else if(m-nk < n){
            debug("sm")
            l = m+1;
        }
        else {
            debug("gr")
            h = m-1;
        }
    }

    cout<<ans<<endl;
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
    pn.clear();
    pn.resize(20);
    for(int i = 0; i<20; i++){
        pn[i] = pow(9,i);
    }
    debug(pn)
    while(t--){
        solve();
    }


} 
