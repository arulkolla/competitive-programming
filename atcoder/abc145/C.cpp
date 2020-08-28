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
    int n;
    cin >> n;
    pair<int, int> p[MAX];
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    long double val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            val += sqrt(pow(p[i].first - p[j].first, 2.0) + pow(p[i].second - p[j].second, 2.0));
        }
    }
    cout << fixed << setprecision(17) << (2.0 * val / (n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {cout << "Case #" << i << ": "; solve();}
    solve();
}