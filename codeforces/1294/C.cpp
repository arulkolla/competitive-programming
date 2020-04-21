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
    set<int> good;
    for (int i = 2; i * i <= n; ++i) {
        if (!(n % i) && !good.count(i)) {good.insert(i); n /= i; break;}
    }
    for (int i = 2; i * i <= n; ++i) {
        if (!(n % i) && !good.count(i)) {good.insert(i); n /= i; break;}
    }
    if (good.size() < 2 || good.count(n) || n == 1) {cout << "NO";}
    else {
        cout << "YES" << endl;
        good.insert(n);
        for (auto w : good) {cout << w << " ";}
    }
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