#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for (int i =(int)(i0); i < (int)(n); i++)
using ll=long long;

string encode(string s){
    string rslt;
    rslt += s[0];

    int lenS = (int)s.size();
    int cnt = 1;
    rep(i, 1, lenS){
        if(s[i]!=s[i-1]){
            rslt += to_string(cnt)+s[i];
            cnt = 1;
        }
        else cnt += 1;
    }
    rslt += to_string(cnt);
    return rslt;
}