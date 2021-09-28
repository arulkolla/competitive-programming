#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve() {
	int n;
	cin >> n;
	pair<int, int> a[n + 7], b[n + 7];
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		b[i] = a[i];
	}
	sort(a, a + n); reverse(a, a + n); sort(b, b + n);
	FenwickTree lt = FenwickTree(n), gt = FenwickTree(n);
	int less[n + 7], grea[n + 7];
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			if (b[i].first == b[i - 1].first) {curr++;}
			else {curr = 0;}
		}
		lt.add(b[i].second, 1);
		int v = lt.sum(0, b[i].second - 1);
		less[b[i].second] = v - curr;
	}
	for (int i = 0; i < n; i++) {
		gt.add(a[i].second, 1);
		int v = gt.sum(0, a[i].second - 1);
		grea[a[i].second] = v;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += min((long long)less[i], (long long)grea[i]);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}