#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

// takes an int and then adds its prime factors with freq to map m;
void add_divs(ll int x, map<ll int, ll int>& m){
    ll int i = 2;
    while(i * i <= x){
        while (x % i == 0){
            m[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) m[x]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll int n;cin>>n;

    vector<bool> v = sieve(n);

    for(int i=1; i<=n; i++){
        if(v[i]) cout<<i<<" ";
    }

}
