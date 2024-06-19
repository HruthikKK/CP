//global variable
vector<ll int> p;
-----------------------------------
void sieve(ull int n){

    vector<bool> v(n+1,1);

    v[0] = 0;v[1] = 0;

    for(ull int i = 2; i<=sqrt(n); i++){
        if(v[i]){
            for(ull j = i*i; j<=n; j+=i) v[j] = 0; 
        }
    }

    for(ll int i = 2; i<=n; i++)
            if(v[i]) p.push_back(i);

}
