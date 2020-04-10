#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int p[n], c[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
    }
    for (int i = 0; i < n; i++) {
        if (p[i-1] > p[i] && i > 0) {cout << "NO"; return;}
        if (c[i-1] > c[i] && i > 0) {cout << "NO"; return;}
        if (p[i] < c[i]) {cout << "NO"; return;}
        if ((i > 0) && (c[i] - c[i-1] > p[i] - p[i-1])) {cout << "NO"; return;}
    }
    cout << "YES";
    return;
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
        cout << endl;
    }
}
