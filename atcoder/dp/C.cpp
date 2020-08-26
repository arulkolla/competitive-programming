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
    int a[MAX][3], n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    // if (n == 1) {cout << max(a[1][0], max(a[1][1], a[1][2]));}
    int dp[MAX][3];
    dp[1][0] = max(a[1][0], max(a[1][1], a[1][2]));
    dp[1][1] = max(a[1][0], max(a[1][1], a[1][2]));
    dp[1][2] = max(a[1][0], max(a[1][1], a[1][2]));
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] + a[i][0], dp[i - 1][2] + a[i][0]);
        dp[i][1] = max(dp[i - 1][2] + a[i][1], dp[i - 1][0] + a[i][1]);
        dp[i][2] = max(dp[i - 1][0] + a[i][2], dp[i - 1][1] + a[i][2]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {cout << "Case #" << i << ": "; solve();}
    solve();
}