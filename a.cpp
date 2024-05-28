#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll int n;
	cin>>n;

    vector<ll int> v(n);
    for(int i =0; i<n; i++) cin>>v[i];

    sort(v.begin(),v.end());

    if(v[0] == v[n-1]){
        cout<<0<<endl;
        return 0;
    }

    ll int tt = 0;
    for(int i = 0; i<n; i++) tt += v[i];

    ll int toC = v[n-2];
    ll int toD = ceil((tt+0.0)/(n-1));

    toC = max(toC,toD);

    ll int ans = toC*(n-1) - tt;
        
    cout<<ans<<endl;
	
}
  
