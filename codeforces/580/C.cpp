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

#define MAX_N 100005

using namespace std;

int a[MAX_N];
vector<int> g[MAX_N];
bool v[MAX_N];
int n, m, ans;

void dfs(int node, int cat) {
    v[node] = true;
    if (a[node]) {cat++;}
    else {cat = 0;}
    if (cat > m) {return;}
    for (int i = 0; i < g[node].size(); i++) {
        if (!v[g[node][i]]) {
            dfs(g[node][i], cat);
        }
    }
    if (g[node].size() == 1 && node != 1) {ans++;}
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}