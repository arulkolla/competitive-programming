#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    long long a[100001] = {0}, n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> k; a[k]++;}
    for (int i = 2; i < 100001; i++) {
        a[i] = max(a[i-1], a[i-2] + a[i] * i);
    }
    cout << a[100000];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        solve();
//        cout << endl;
//    }
    solve();
}