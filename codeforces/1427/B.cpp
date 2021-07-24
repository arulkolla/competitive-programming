#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct run {
	int val;
	int len;
	int l;
	int r;
	run(int left, int right) {
		l = left;
		r = right;
		len = r - l + 1;
		val = 2 * len + 1;
	}
};

bool cmp(const run& v1, const run& v2) {
	if (v1.val != v2.val) {return v1.val < v2.val;}
	if (v1.len != v2.len) {return v1.len < v2.len;}
	return v1.l < v2.l;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int score = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			score++;
			if (i > 0 && s[i - 1] == 'W') {score++;}
		}
	}
	vector<pair<int, int> > v;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'L') {
			if (s[i - 1] == 'W') {
				l = i; r = i;	
			}
			else {
				r++;
			}
		}
		else {
			if (s[i - 1] == 'W') {
				// do nothing
			}
			else {
				v.emplace_back(l, r);
			}
		}
	}
	if (s[n - 1] == 'L') {v.emplace_back(l, r);}
	vector<run> vals;
	for (auto p : v) {
		if (p.first != 0 && p.second != n - 1) {
			run curr = run(p.first, p.second); vals.push_back(curr);
		}
	}
	sort(vals.begin(), vals.end(), cmp);
	int diff = 0;
	bool other = false;
	for (int i = 0; i < vals.size(); i++) {
		if (k >= vals[i].len) {diff += vals[i].val; k -= vals[i].len;}
		else {other = true;}
	}
	if (k > 0) {
		if (other) {diff += 2 * k;}
		else {
			int fl = 0, fr = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'L') {fl++;}
				else {break;}
			}
			if (fl != n) {
				for (int i = n - 1; i >= 0; i--) {
					if (s[i] == 'L') {fr++;}
					else {break;}
				}
			}
			else {
				cout << 2 * min(n, k) - 1 << endl; return;
			}
			int side = (s[0] == 'L') + (s[n - 1] == 'L'), notside = fl + fr - side;
			if (k <= notside) {diff += 2 * k;}
			else if (k + 1 == notside) {diff += 2 * (k - 1) + 1;}
			else {diff += 2 * min(k, fl + fr);}
		}
	}
	cout << score + diff << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}