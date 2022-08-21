#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for (int i =(int)(i0); i < (int)(n); i++)
using ll=long long;

void BubbleSort(vector<int> &vec){
    int lenV = vec.size();
    rep(i, 0, lenV){
        rep(j, i+1, lenV){
            if (vec[i]>vec[j]) swap(vec[i], vec[j]);
        }
    }
}

void SelectionSort(vector<int> &vec){
    int lenV = vec.size();
    rep(i, 0, lenV-1){
        auto min_element_itr = *min_element(vec.begin()+i, vec.end());
        swap(vec[i], *min_element_itr);
    }
}

void InsersionSort(vector<int> &vec){
    int lenV = vec.size();
    rep(i, 1, lenV){
        int pos = i;
        while (pos && vec[pos-1]>vec[pos]){
            swap(vec[pos-1], vec[pos]);
            pos--;
        }
    }
}