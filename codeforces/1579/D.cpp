#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			pq.push(make_pair(a, i + 1));
		}
	}
	vector<pair<int, int> > res;
	while (pq.size() >= 2) {
		pair<int, int> p1 = pq.top(); pq.pop();
		pair<int, int> p2 = pq.top(); pq.pop();
		res.emplace_back(p1.second, p2.second);
		p1.first--; p2.first--;
		if (p1.first != 0) {pq.push(p1);}
		if (p2.first != 0) {pq.push(p2);}
	}
	cout << res.size() << '\n';
	for (auto p : res) {
		cout << p.first << ' ' << p.second << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}