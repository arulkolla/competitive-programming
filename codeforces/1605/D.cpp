#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool color[MAX], vis[MAX];
int a[MAX], tcnt = 0, fcnt = 0;

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			color[i] = !color[v];
			dfs(i);
		}
	}
}

void clear(int n) {
	for (int i = 0; i < n + 7; i++) {
		g[i].clear();
		color[i] = false;
		vis[i] = false;
		a[i] = -1;
	}
	tcnt = 0;
	fcnt = 0;
}

void solve() {
	int n;
	cin >> n;
	clear(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	color[1] = true; dfs(1); // color teal and fuschia
	for (int i = 1; i <= n; i++) {
		if (color[i]) {
			tcnt++;
		}
		else {
			fcnt++;
		}
	}
	bool sw = false;
	if (tcnt > fcnt) {swap(tcnt, fcnt); sw = true;}
	// cout << "tcnt: " << tcnt << " fcnt: " << fcnt << '\n';
	int fstore = fcnt;
	vector<int> t, f;
	int pow2 = 0;
	while (tcnt > 0 || fcnt > 0) {
		if (tcnt & 1) {
			t.push_back(pow2);
		}
		else {
			f.push_back(pow2);
		}
		pow2++;
		tcnt >>= 1;
		fcnt >>= 1;
	}
	vector<int> tall, fall;
	for (int i : t) {
		for (int j = (1 << i); j < min((1 << (i + 1)), n + 1); j++) {
			tall.push_back(j);
		}
	}
	for (int i : f) {
		for (int j = (1 << i); j < min((1 << (i + 1)), n + 1); j++) {
			fall.push_back(j);
		}
	}
	int last = n;
	while (fall.size() < fstore) {
		fall.push_back(last);
		last--;
	}
	// cout << "tall: "; for (int i : tall) {cout << i << ' ';} cout << '\n';
	// cout << "fall: "; for (int i : fall) {cout << i << ' ';} cout << '\n';
	int pt1 = 0, pt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (sw ^ color[i]) {
			a[i] = tall[pt1]; pt1++;
		}
		else {
			a[i] = fall[pt2]; pt2++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}