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
    unsigned long long int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        if (k <= n/2) {
            cout << 2 * k - 1;
        }
        else {
            cout << 2 * (k - n/2);
        }
    }
    else if (n % 2 == 1) {
        if (k <= n/2 + 1) {
            cout << 2 * k - 1;
        }
        else {
            cout << 2 * (k - n/2 - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}