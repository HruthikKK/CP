// give the vector of size 32(meaning 32 bit no.) as arg in usual rep 
ll int bToD(vector<int>& v){
    
    ll int n =0;
    ll int p = 1;
    for(int i = 31; i>=0; i++){
        if(v[i]) n += p;
        p*=2;
    }
    return n;
}