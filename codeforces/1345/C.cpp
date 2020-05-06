#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            a[i] += (abs(a[i])/n)*n + n;
        }
        b[i] = (a[i] + i)%n;
    }
    sort(b, b+n);
    for (int i = 1; i < n; i++) {
        if (b[i] - b[i-1] != 1) {cout << "NO"; return;}
    }
    cout << "YES";
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
//    solve();
}