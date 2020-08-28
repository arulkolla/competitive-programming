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

const int MAX = 107;
const int MOD = 1000000007;

void solve() {
    int n, w;
    cin >> n >> w;
    long weight[MAX], value[MAX];
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    long dp[n + 7][w + 7];
    for (int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (weight[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {cout << "Case #" << i << ": "; solve();}
    solve();
}