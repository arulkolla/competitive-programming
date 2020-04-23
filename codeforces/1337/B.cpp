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
    int x, n, m;
    cin >> x >> n >> m;
    if (x <= 10 && m >= 1) {
        cout << "YES"; return;
    }
    for (int i = 0; i < n; i++) {
        x /= 2;
        x += 10;
    }
    if (x <= 10*m) {cout << "YES"; return;}
    cout << "NO";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
    //solve();
}