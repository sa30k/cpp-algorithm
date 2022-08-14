#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for (int i =(int)(i0); i < (int)(n); i++)
using ll=long long;

void bubblesort(vector<int> &vec){
    int lenV = vec.size();
    rep(i, 0, lenV){
        rep(j, i+1, lenV){
            if (vec[i]>vec[j]){
                int smaller = vec[j];
                vec[j] = vec[i];
                vec[i] = smaller;
            }
        }
    }
}