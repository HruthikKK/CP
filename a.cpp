#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> p;
set<ll int> s;
ll int n,k;

vector<bool> sieve(ll int n){

    vector<bool> v(n+1,1);

    v[0] = 0;v[1] = 0;

    for(ll int i = 2; i<=sqrt(n); i++){
        if(v[i]){
            for(ll j = i*i; j<=n; j+=i) v[j] = 0; 
        }
    }

	p = v;
    return v;
}

bool check(ll int n){

	if(2>k && (n%2 == 0)) return 1;
	while (n%2 == 0)
    {
		n/=2;
    }
 
    for (int i = 3; i*i <= n; i = i+2)
    {
        if(i>k && (n%i==0)) return 1;
        while (n%i == 0)
        {
            n = n/i;
        }
    }
 
    if (n > k) return 1;
	else return 0;
}

int main()
{

	// vector<bool> p = sieve(n);
	cin>>n>>k;

	ll ans = n;
	s.clear();

	for(int i = k+1; i<=n; i++){
		if(check(i)) ans--;
	}

	cout<<ans<<endl;
}
  
