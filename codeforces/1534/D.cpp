#include <bits/stdc++.h>

using namespace std;

const int MAX = 2007;
const int MOD = 1000000007;

int n, temp;
bool vis[MAX] = {};
vector<int> g[MAX];

vector<int> query(int x) {
	vector<int> res;
	cout << "? " << x << endl;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		if (temp % 2 == 0 && temp != 0) {
			res.push_back(i);
		}
		if (temp == 1) {
			g[x].push_back(i);
			g[i].push_back(x);
		}
	}
	return res;
}

void solve() {
	cin >> n;
	vector<int> curr;
	curr = query(1);
	if (curr.size() + 1 > n / 2) {
		curr = query(g[1][0]);
		vis[g[1][0]] = true;
	}
	else {
		vis[1] = true;
	}
	for (int i : curr) {
		query(i);
	}
	cout << "!" << endl;
	set<pair<int, int> > edges;
	for (int i = 1; i <= n; i++) {
		for (int j : g[i]) {
			if (i < j) {
				edges.insert(make_pair(i, j));
			}
		}
	}
	for (pair<int, int> p : edges) {
		cout << p.first << ' ' << p.second << endl;
	} 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}