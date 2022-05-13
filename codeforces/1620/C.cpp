#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long k, x;
	cin >> n >> k >> x;
	x--;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	vector<long long> v;
	long long curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			if (curr != 0) {v.push_back(k * curr + 1); curr = 0;}
		}
		else {
			curr++;
		}
	}
	if (curr != 0) {v.push_back(k * curr + 1); curr = 0;}
	if (v.empty()) {cout << s << '\n'; return;}
	vector<long long> w;
	for (long long i : v) {
		w.push_back(x % i);
		x /= i;
	}
	reverse(w.begin(), w.end());
	reverse(s.begin(), s.end());
	int pt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			if (i + 1 == n || s[i + 1] == 'a') {
				for (int j = 0; j < w[pt]; j++) {cout << 'b';} pt++;
			}
		}
		else {cout << 'a';}
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}