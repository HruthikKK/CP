ll int inverseModp(ll int a, ll int p) {
    assert(p < (1ull << 63));
    assert(a < p);
    assert(a != 0);
    ll int ex = p-2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result*a) % p;
        }
        a = (a*a) % p;
        ex /= 2;
    }
    return result;
}

// p MUST be prime
ll int nCrModp(ll int n, ll int r, ll int p)
{
    assert(r <= n);
    if (r > n-r) r = n-r;
    if (r == 0) return 1;
    if(n/p - (n-r)/p > r/p) return 0;

    ll int result = 1; //intermediary results may overflow 32 bits

    for (ll int i = n, x = 1; i > r; --i, ++x) {
        if( i % p != 0) {
            result *= i % p;
            result %= p;
        }
        if( x % p != 0) {
            result *= inverseModp(x % p, p);
            result %= p;
        }
    }
    return result;
}