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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (m * a <= b) {cout << n * a;}
    else {cout << (n/m) * b + min((n%m) * a, b);}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//        cout << endl;
//    }
    solve();
}