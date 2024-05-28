#include <bits/stdc++.h>
using namespace std;
#define ll long long

static bool sortbyCond(const vector<ll int>& a,const vector<ll int>& b){
    if(a[0] == b[0]) return b[1]>a[1];
    return a[0]>b[0];
}

int main()
{
    ll int n;
    cin>>n;

    vector<vector<ll int>> v(n,vector<ll int>(2));
    for(int i = 0; i<n; i++){
        cin>>v[i][0];
        v[i][1] = i;
    }
    sort(v.begin(),v.end(),sortbyCond);
    
    // for(int i =0; i<n; i++){
    //     cout<<v[i][0]<<" "<<v[i][1]<<endl; sort(v.begin(),v.end(),sortbyCond);
    // }

    vector<ll int> vis(n+1,0);

    ll int ans =0;

    for(int i = 0; i<n; i++){
        ll int cI = v[i][1];
        if(!vis[cI]){
            vis[cI] = 1;
            vis[cI+1] = 1;
            ans += v[i][0];
        }
    }

    cout<<ans<<endl;
}

  
