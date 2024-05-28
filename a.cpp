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
}

int main()
{

    ll int n;
    cin>>n;
    m.clear();

    ll int tp;
    for(int i = 0; i<n; i++){
        cin>>tp;
        check(tp);
    }  

    for(auto x:m){
        if(x.second == 1){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    
}

  
