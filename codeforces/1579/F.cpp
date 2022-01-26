#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

int n, d, gap, a[MAX];
bool vis[MAX];

int gcd(int a, int b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

int dfs(int x){
	vis[x] = true;
	if (a[x] == 0) {return 0;}
	else {return dfs((x + d) % n) + 1;}
}

void solve() {
	memset(vis, false, sizeof(vis));
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// vis[i] = false;
	}
	int res = -MOD;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0){
			vis[i] = true;
			res = max(dfs((i + d) % n), res);
		}
	}
	bool ok = true;
	for(int i = 0; i < n; i++){
		if (!vis[i]) {ok = false;}
	}
	if (ok) {cout << res << '\n';}
	else {cout << -1 << '\n';}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}