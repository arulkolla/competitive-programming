#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 107;
const int MOD = 1000000007;

void solve() {
    int x, n;
    cin >> x >> n;
    int p[MAX];
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == x) {ok = false;}
    }
    if (ok) {cout << x; return;}
    sort(p, p + n);
    for (int i = 1; i <= INT_MAX; i++) {
        bool okS = true, okL = true;
        for (int j = 0; j < n; j++) {
            if (x-i == p[j]) {
                okS = false;
            }
            else if (x+i == p[j]) {
                okL = false;
            }
        }
        if (okS) {
            cout << x-i; return;
        }
        else if (okL) {
            cout << x+i; return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
