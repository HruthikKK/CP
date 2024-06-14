#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll int, ll int> m;

void check(ll int n){

	if((n%2 == 0)){
        m[2]++;
        while (n%2 == 0)
        {
            n/=2;
        }
    }

    for (int i = 3; i*i <= n; i = i+2)
    {
        if((n%i==0)){
            m[i]++;
            while (n%i == 0)
            {
                n = n/i;
            }
        }
    }
    if (n > 1){
        m[n]++;
    }
}

bool check2(ll int n){
    if((n%2 == 0)){
        if(m[2]>1) return 1;
        while (n%2 == 0)
        {
            n/=2;
        }
    }

    for (int i = 3; i*i <= n; i = i+2)
    {
        if((n%i==0)){
            if(m[i] > 1) return 1;
            while (n%i == 0)
            {
                n = n/i;
            }
        }
    }
    if (n > 1){
        if(m[n]>1) return true;
    }

    return false;
}

int main()
{

    ll int n;
    cin>>n;
    m.clear();

    ll int tp;
    vector<ll int> v(n);
    for(int i = 0; i<n; i++){
        cin>>tp;
        v[i] = tp;
        check(tp);
    }  

    // for(auto x:m){
    //     cout<<x.first<<" "<<x.second<<endl;  
    // }

    for(int i = 0; i<n; i++){
        bool fg = check2(v[i]);
        if(!fg){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    
}

  
