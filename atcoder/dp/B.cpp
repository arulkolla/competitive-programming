#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
    int n, k, h[MAX];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i + 1];
    }
    int dp[MAX];
    dp[1] = 0;
    for (int i = 2; i <= k; i++) {
        int mn = 2147483647;
        for (int j = 1; j < i; j++) {
            mn = min(mn, dp[i - j] + abs(h[i] - h[i - j]));
        }
        dp[i] = mn;
    }
    for (int i = k + 1; i <= n; i++) {
       int mn = 2147483647;
       for (int j = 1; j <= k; j++) {
           mn = min(mn, dp[i - j] + abs(h[i] - h[i - j]));
       }
       dp[i] = mn;
    }
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {cout << "Case #" << i << ": "; solve();}
    solve();
}