// returns vector of size 32 represting no. n in 32 bit usual rep.
vector<int> dToB(ll int n){

    vector<int> v;
    while(n){
        if(n&1) v.push_back(1);
        else v.push_back(0);
        n/=2;
    }
    while(v.size()<32) v.push_back(0);
    reverse(all(v));
    return v;
}