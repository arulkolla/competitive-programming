#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    vector<int> switches;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b = a[0];
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        if ((a[i] > 0 && a[i-1] < 0) || (a[i] < 0 && a[i-1] > 0)) {
            sum += b;
            b = a[i];
            continue;
        }
        else {
            b = max(a[i], b);
        }
    }
    sum += b;
    cout << sum;
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