#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct inter {
	long long l, r;
	inter(long long lv, long long rv) {
		l = lv;
		r = rv;
	}
	bool hits(long long x) {
		return (min(l, r) <= x && x <= max(l, r));
	}
	bool corner(inter other) {
		return r == other.l;
	}
	bool dec() {
		return l > r;
	}
	bool dec(long long x) {
		return (l > x && r < x);
	}
	bool wkdec(long long x) {
		return r < x;
	}
};

void solve() {
	int n;
	cin >> n;
	long long curr = 0;
	set<long long> eventset;
	vector<inter> v;
	eventset.insert(curr); eventset.insert(curr + 1);
	long long val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		if (i % 2 == 1) {val = -val;}
		v.push_back(inter(curr, curr + val));
		curr += val;
		eventset.insert(curr); eventset.insert(curr + 1);
	}
	vector<long long> events;
	for (auto i : eventset) {events.push_back(i);}
	long long res = 0;
	for (int ind = 0; ind < events.size() - 1; ind++) {
		long long x = events[ind], rn = 0;
		// cout << x << ":\n";
		vector<inter> curr;
		bool start = false;
		for (auto i : v) {
			if (i.hits(x)) {
				// cout << i.l << ' ' << i.r << " considering\n";
				if (start || !i.dec()) {
					// cout << i.l << ' ' << i.r << " pushed back\n";
					curr.push_back(i); 
					start = true;
				}
			}
		}
		long long cnt = 0;
		for (auto i : curr) {
			if (!i.dec()) {
				// cout << "increasing: " << i.l << ' ' << i.r << '\n';
				cnt++;
			}
			else if (i.dec(x)) {
				// cout << cnt << '\n'; 
				rn += (cnt * (cnt + 1)) / 2; cnt = 0;
			}
			else if (i.wkdec(x)) {
				cnt = 0;
			}
		}
		if (cnt != 0) {
			if (curr[curr.size() - 1].dec()) {
				// cout << cnt << " end" << '\n'; 
				rn += (cnt * (cnt + 1)) / 2;
			}
			else {
				// cout << cnt << " end" << '\n'; 
				rn += (cnt * (cnt - 1)) / 2;
			}
		}
		// cout << rn << " multiplier: " << events[ind + 1] - events[ind] << '\n';
		res += (rn * (events[ind + 1] - events[ind]));
		// cout << '\n';
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}