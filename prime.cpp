#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for (int i =(int)(i0); i < (int)(n); i++)
using ll=long long;

bool is_prime(ll n) {
    for(ll p = 2; p*p <= n; p++) {
        if(n % p == 0) return false;
    }
    
    return true;
}

vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p*p <= N; p++) {
        if (N % p != 0) continue;
        ll ex = 0; 

        while (N % p == 0) {
            ex++;
            N /= p;
        }

        res.push_back({p, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

