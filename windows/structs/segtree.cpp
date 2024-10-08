#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2 * N];

void build(vector<int>& arr) {
    for (int i = 0; i < n; i++) t[n+i] = arr[i];
    for (int i = n - 1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += t[l++];
        if (r&1) ans += t[--r];
    }
    return ans;
}
