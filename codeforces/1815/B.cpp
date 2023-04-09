#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int qcount = 0;

void qadd(int x) {
	cout << "+ " << x << endl;
	int resp;
	cin >> resp;
	qcount++;
	return;
}

int query(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int resp;
	cin >> resp;
	qcount++;
	return resp;
}

void solve() {
	qcount = 0;
	int n;
	cin >> n;
	// get the ordering
	vector<int> v, g[n + 7];
	if (n == 2) {
		cout << "! 1 2 2 1" << endl;
		int resp;
		cin >> resp;
		return;
	}	
	else if (n == 3) {
		qadd(3);
		qadd(4);
		v.push_back(2);
		v.push_back(1);
		v.push_back(3);
	}
	else {
		qadd(n / 2 + 1);
		qadd(n / 2 + 2);
		qadd(n / 2 + n + 1);
		qadd(n / 2 + n + 2);
		vector<int> xs;
		xs.push_back(n / 2 + 1);
		xs.push_back(n / 2 + 2);
		xs.push_back(n / 2 + n + 1);
		xs.push_back(n / 2 + n + 2);
		
		int one = -1;
		for (int x : xs) {
			for (int i = 1; i <= n; i++) {
				if (1 <= x - i && x - i <= n && i != x - i) {
					g[i].push_back(x - i);
				}
			}
		}
		bool vis[n + 7];
		for (int i = 1; i <= n; i++) {
			vis[i] = false;
			// cout << i << ": ";
			// for (int xx : g[i]) {cout << xx << ' ';}
			// cout << '\n';
		}
		for (int i = 1; i <= n; i++) {
			if (g[i].size() == 1) {one = i; break;}
		}
		assert(one != -1);
		v.push_back(one);
		vis[one] = true;
		queue<int> q;
		q.push(one);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int w : g[u]) {
				if (!vis[w]) {
					vis[w] = true;
					q.push(w);
					v.push_back(w);
				}
			}
		}
		// cout << "FOR DEBUG ONLY: ";
		// for (int i : v) {cout << i << ' ';} cout << endl;
	}
	// now we have v, let's try and find the answer
	vector<int> dist[n + 7], ndist[n + 7];
	int actual[n + 7];
	int mx = -1, mxval = -1;
	for (int i = 2; i <= n; i++) {
		int x = query(1, i);
		dist[x].push_back(i);
		if (x > mx) {
			mx = x;
			mxval = i;
		}
	}
	// disambiguate dists
	for (int i = 1; i <= mx; i++) {
		if (dist[i].size() == 1) {
			ndist[mx - i].push_back(dist[i][0]);
		}
		else {
			ndist[mx - i].push_back(dist[i][0]);
			ndist[mx - i].push_back(dist[i][1]);
		}
	}
	ndist[mx].push_back(1);
	// for (int i = 0; i <= mx; i++) {
		// cout << i << " " << ndist[i].size() << ": ";
		// for (int qq : ndist[i]) {cout << qq << ' ';}
		// cout << '\n';
	// }
	for (int i = 0; i <= mx; i++) {
		if (ndist[i].size() >= 2) {
			int resp;
			if (mxval == ndist[i][0]) {resp = 0;}
			else {resp = query(mxval, ndist[i][0]);}
			if (resp == i) {
				actual[i] = ndist[i][0];
				actual[2 * mx - i] = ndist[i][1];
			}
			else {
				actual[i] = ndist[i][1];
				actual[2 * mx - i] = ndist[i][0];
			}
		}
		else {
			actual[i] = ndist[i][0];
		}
	}
	pair<int, int> p[n + 7];
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		p[i] = make_pair(v[i], actual[i]);
	}
	sort(p, p + n);
	pair<int, int> aaaa[n + 7];
	cout << "! ";
	
	for (int i = 0; i < n; i++) {
		aaaa[i] = make_pair(p[i].second, i + 1);
	}
	sort(aaaa, aaaa + n);
	for (int i = 0; i < n; i++) {
		cout << aaaa[i].second << ' ';
	}
	reverse(actual, actual + n);
	for (int i = 0; i < n; i++) {
		p[i] = make_pair(v[i], actual[i]);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		aaaa[i] = make_pair(p[i].second, i + 1);
	}
	sort(aaaa, aaaa + n);
	for (int i = 0; i < n; i++) {
		cout << aaaa[i].second << ' ';
	}
	// for (int i = 0; i < n; i++) {
		// cout << p[i].second;
		// if (i != n - 1) {cout << ' ';}
	// }
	cout << endl;
	int resp;
	cin >> resp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}