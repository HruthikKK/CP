#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

// returns a vector  of size = n+1
vector<bool> sieve(ull int n){

    vector<bool> v(n+1,1);

    v[0] = 0;v[1] = 0;

    for(ull int i = 2; i<=sqrt(n); i++){
        if(v[i]){
            for(ull j = i*i; j<=n; j+=i) v[j] = 0; 
        }
    }

    return v;
}

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