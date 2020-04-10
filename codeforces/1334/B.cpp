#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    std::sort(a, a+n, std::greater<>());
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum / (double)(i+1) < x) { cout << i; return; }
    }
    cout << n;
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