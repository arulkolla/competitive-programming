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

static int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int k, l, res = 1;
    cin >> k;
    for (int i = 1; i < n; i++) {
        l = k;
        cin >> k;
        if (k != l) {
            res++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}