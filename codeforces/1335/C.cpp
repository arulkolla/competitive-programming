#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        m = std::max(m, mp[a[i]]);
    }
    int k = mp.size() - 1;
    if (m - k >= 2) {m--; k++;}
    cout << std::min(m, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
}