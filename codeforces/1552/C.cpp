#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool inter(pair<int, int> p1, pair<int, int> p2) {
	bool b11 = (p1.first < p2.first && p2.first < p1.second);
	bool b12 = (p1.first < p2.second && p2.second < p1.second);
	bool b21 = (p2.first < p1.first && p1.first < p2.second);
	bool b22 = (p2.first < p1.second && p1.second < p2.second);
	// cout << ": " << ((b11 ^ b12) || (b21 ^ b22)) << endl;
	return ((b11 ^ b12) || (b21 ^ b22));
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > v;
	bool vis[2 * n + 7];
	for (int i = 0; i < 2 * n + 7; i++) {vis[i] = false;}
	for (int i = 0; i < k; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v.emplace_back(min(v1, v2), max(v1, v2));
		vis[v1] = true;
		vis[v2] = true;
	}
	vector<int> nhit;
	for (int i = 1; i <= 2 * n; i++) {
		if (!vis[i]) {
			nhit.push_back(i);
		}
	}
	int hf = nhit.size() / 2;
	for (int i = 0; i < hf; i++) {
		v.emplace_back(min(nhit[i], nhit[i + hf]), max(nhit[i], nhit[i + hf]));
	}
	// for (int i = 0; i < n; i++) {cout << v[i].first << ' ' << v[i].second << endl;} 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// cout << v[i].first << ' ' << v[i].second << ',' << v[j].first << ' ' << v[j].second;
			if (inter(v[i], v[j])) {cnt++;}
		}
	}
	cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}