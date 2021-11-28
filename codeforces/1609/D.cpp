#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int a[MAX], sz[MAX], cnt[MAX], extra[MAX];
bool head[MAX];
 
int find(int p) {
	while (p != a[p]) {
		a[p] = a[a[p]];
		p = a[p];
	}
	return p;
}
 
bool connected(int p, int q) {
	return find(p) == find(q);
}
 
void dsu(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i != j) {
		if (sz[i] < sz[j]) {cnt[j] += cnt[i]; extra[j] += extra[i]; a[i] = j; head[i] = false;}
		else if (sz[i] > sz[j]) {cnt[i] += cnt[j]; extra[i] += extra[j]; a[j] = i; head[j] = false;}
		else {
			cnt[i] += cnt[j];
			extra[i] += extra[j];
			a[j] = i;
			head[j] = false;
			sz[i]++;
		}
	}
	else {
		extra[i]++;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		sz[i] = 0;
		extra[i] = 0;
		cnt[i] = 1;
		head[i] = true;
	}
	for (int q = 0; q < m; q++) {
		int x, y;
		cin >> x >> y;
		dsu(x, y);
		int mx = -1, big = -1;
		for (int i = 1; i <= n; i++) {
			if (head[i]) {
				if (cnt[i] > mx) {
					mx = cnt[i];
					big = i;
				}
			}
		}
		vector<int> v;
		int tot = extra[big];
		for (int i = 1; i <= n; i++) {
			if (head[i] && i != big) {
				tot += extra[i]; v.push_back(cnt[i]);
			}
		}
		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < min((int)v.size(), tot); i++) {
			mx += v[i];
		}
		cout << mx - 1 << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}