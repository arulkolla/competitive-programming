#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int n;
int a[MAX], res[MAX];
vector<int> g[MAX];
bool vis[MAX] = {};
bool iscyc[MAX] = {};
bool isgood[MAX] = {};
bool uhhh[MAX] = {};
vector<int> cyc;
vector<int> curr, rn;
int start;

void dfs(int v) {
	vis[v] = true;
	curr.push_back(v);
	if (!vis[a[v]]) {
		dfs(a[v]);
	}
	else {
		start = a[v];
	}
}

void dfsg(int v) {
	rn.push_back(v);
	vis[v] = true;
	if (!vis[a[v]] && !iscyc[a[v]]) {
		dfsg(a[v]);
	}
}

void clear(int n) {
	for (int i = 0; i < n + 7; i++) {
		vis[i] = false;
		iscyc[i] = false;
		isgood[i] = false;
		uhhh[i] = false;
		res[i] = -1;
		g[i].clear();
	}
	cyc.clear();
	curr.clear();
	rn.clear();
	start = -1;
}

void solve() {
	cin >> n;
	clear(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			bool hit = false;
			for (int j : curr) {
				if (j == start) {
					hit = true;
				}
				if (hit) {
					cyc.push_back(j);
					iscyc[j] = true;
				}
			}
			curr.clear();
		}
	}
	for (int i = 0; i < n + 7; i++) {
		vis[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].empty()) {
			dfsg(i);
			for (int j = 0; j < rn.size() - 1; j++) {
				isgood[rn[j]] = true;
			} 
			rn.clear();
		}
	}
	int cnt = 0;
	vector<int> left, leftu;
	for (int i = 1; i <= n; i++) {
		if (isgood[i] || iscyc[i]) {
			cnt++; 
			res[i] = a[i];
			uhhh[a[i]] = true;
		}
		else {
			left.push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!uhhh[i]) {
			leftu.push_back(i);
		}
	}
	if (left.size() == 1) {
		if (left[0] != leftu[0]) {
			res[left[0]] = leftu[0];
		}
		else {
			int befval;
			for (int i = 1; i <= n; i++) {
				if (res[i] == a[left[0]]) {befval = i;}
			}
			res[befval] = left[0];
			res[left[0]] = a[left[0]];
		}
	}
	else if (!left.empty()) {
		vector<int> self, l1, l2;
		for (int i = 1; i <= n; i++) {
			if (!(isgood[i] || iscyc[i]) && !uhhh[i]) {
				self.push_back(i);
			}
			else if (!(isgood[i] || iscyc[i])) {
				l1.push_back(i);
			}
			else if (!uhhh[i]) {
				l2.push_back(i);
			}
		}
		vector<int> t1, t2;
		for (int i : self) {t1.push_back(i); t2.push_back(i);}
		for (int i : l1) {t1.push_back(i);}
		for (int i : l2) {t2.push_back(i);}
		
		for (int i = 0; i < t1.size(); i++) {
			res[t1[i]] = t2[(i + 1) % t2.size()];
		}
	}
	
	int realcnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == res[i]) {realcnt++;}
	}
	cout << realcnt << endl;
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
		assert(res[i] != i);
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}