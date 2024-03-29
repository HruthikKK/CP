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
    return a[1]>b[1];
}

// ------------------------------------------------------------------------- //

// GLOBAL VAR------------------------------------------------------------------------- //

ll int n;
vector<ll int> v(2*1e5 + 7);

// ------------------------------------------------------------------------- //

void mergeSort(ll int l,ll int m, ll int h){

    vector<ll int> a;
    for(int i = l; i<m; i++) a.push_back(v[i]);
    vector<ll int> b;
    for(int i =m; i<=h; i++) b.push_back(v[i]);

    ll int i = 0,j = 0,k = l;
    ll int as = a.size(),bs = b.size();
    while(i<as && j<bs){
        if(a[i]<b[j]){
            v[k] = a[i];
            i++; 
            k++;
        }
        else{
            v[k] = b[j];
            j++;
            k++;
        }
    }

    while(i<as){
        v[k] = a[i];
        i++; 
        k++;
    }
    while(j<bs){
        v[k] = b[j];
        j++;
        k++; 
    }

}
ll int reversePairs(ll int l,ll int h){

    if(l >= h) return 0;

    ll int m = (l+h)/2;//m is mid or rightMid
    if((h-l) & 1) m++;//even ele in seg
    ll int cA = reversePairs(l,m-1);
    cA += reversePairs(m,h);

    ll int i1 = l;
    ll int i2 = m;
    
    while(i1<m && i2<=h){
        if(v[i1]>v[i2]){
            cA += (m-i1);
            i2++;
        }
        else i1++;
    }

    mergeSort(l,m,h);

    return cA;
}

void solve(){

    ll int ans =0;
    cin>>n;

    for(int i =0; i<n; i++) cin>>v[i];

    ans = reversePairs(0,n-1);

    cout<<ans<<endl;
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
    cin>>t;

    while(t--){
        solve();
    }

} 