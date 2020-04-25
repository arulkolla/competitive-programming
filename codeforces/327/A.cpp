#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < i; k++) {if (a[k] == 1) {cnt++;}}
            for (int k = j + 1; k < n; k++) {if (a[k]==1) {cnt++;}}
            for (int k = i; k <= j; k++) {if (a[k]==0) {cnt++;}}
            ans = max(ans,cnt);
        }
    }
    cout << ans;
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