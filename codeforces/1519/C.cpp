#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> g[n + 7];
    long long a[n + 7], b[n + 7];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        g[a[i]].push_back(b[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), greater<int>());
    }
    long long res[n + 7];
    for (int i = 1; i <= n; i++) {
        res[i] = 0ll;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < g[i].size(); j++) {
            g[i][j] += g[i][j - 1];
        }
        for (int j = 1; j <= g[i].size(); j++) {
            res[j] += g[i][g[i].size() - 1 - (g[i].size() % j)];
        }
    }
    for (int i = 1; i <= n; i++) {cout << res[i] << ' ';} cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 0; i < tt; i++) {solve();}
	//solve();
	return 0;
}
