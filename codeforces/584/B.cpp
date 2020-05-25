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
    unsigned long long threeCount = 1, sevenCount = 1;
    for (int i = 0; i < 3*n; i++) {
        threeCount = threeCount * 3 % MOD;
    }
    for (int i = 0; i < n; i++) {
        sevenCount = sevenCount * 7 % MOD;
    }
    if (threeCount >= sevenCount) {
        cout << (threeCount - sevenCount) % MOD;
    }
    else {
        cout << (threeCount - sevenCount + MOD) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}