#include <bits/stdc++.h>
using namespace std;
#define rep(i,i0,n) for (int i =(int)(i0); i < (int)(n); i++)
using ll=long long;

mt19937 mt;
random_device rnd;

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

void QuickSort(vector<int> &vec) {
    if (!vec.size()) return;

    int lenV = vec.size();
    int x = lenV/2;
    vector<int> l, r;
    rep(i, 0, lenV){
        if (i==x) continue;
        if (vec[i]<vec[x]) l.push_back(vec[i]);
        else r.push_back(vec[i]);
    }

    QuickSort(l);
    QuickSort(r);

    l.push_back(vec[x]);
    l.insert(l.end(), r.begin(), r.end());
    vec = l;
}

void RandomQuickSort(vector<int> &vec) {
    if (!vec.size()) return;

    int lenV = vec.size();
    int x = mt() % lenV;
    vector<int> l, r;
    rep(i, 0, lenV){
        if (i==x) continue;
        if (vec[i]==vec[x]){
            if (mt()%2) l.push_back(vec[i]);
            else r.push_back(vec[i]);
        }
        else if (vec[i]<vec[x]) l.push_back(vec[i]);
        else r.push_back(vec[i]);
    }

    RandomQuickSort(l);
    RandomQuickSort(r);

    l.push_back(vec[x]);
    l.insert(l.end(), r.begin(), r.end());
    vec = l;
}

void MergeSort(vector<int> &vec) {
    int lenV = vec.size();
    if (!lenV) return;
    
    int x = lenV/2;
    vector<int> l, r;
    copy(vec.begin(), vec.begin()+x, back_inserter(l));
    copy(vec.begin()+x, vec.end(), back_inserter(r));

    if (l.size()>=2) MergeSort(l);
    if (r.size()>=2) MergeSort(r);

    deque<int> dq;
    for (auto x: l) dq.push_back(x);
    reverse(r.begin(), r.end());
    for (auto x: r) dq.push_back(x);

    vec.clear();
    while (dq.size()) {
        if (dq.front()<=dq.back()) {
            vec.push_back(dq.front());
            dq.pop_front();
        }
        else {
            vec.push_back(dq.back());
            dq.pop_back();
        }
    }
}