#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    long double maxDiff = -1.0;
    for (int i = 1; i < n; i++) {
        maxDiff = max((long double)(a[i]-a[i-1])/2.0, maxDiff);
    }
    maxDiff = max(a[0]-(long double)0.0,maxDiff);
    maxDiff = max((long double)l-a[n-1],maxDiff);
    cout << fixed << maxDiff;
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