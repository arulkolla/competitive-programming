#include <bits/stdc++.h>

using namespace std;

const long long GEN = 31;
const int MAX = 200007;
const long long MOD = 1440551621LL;

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
        	res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long x) {
	return binpow(x, MOD - 2);
}

bool pal(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return (s == t);
}

void solve() {
	string sold;
	cin >> sold;
	if (pal(sold)) {cout << sold << '\n'; return;}
 	int ptl = 0, ptr = sold.length() - 1;
	while (ptl < ptr && sold[ptl] == sold[ptr]) {
		ptl++;
		ptr--;
	}
	string start, s;
	for (int i = 0; i < ptl; i++) {start += sold[i];}
	for (int i = ptl; i <= ptr; i++) {s += sold[i];}
	// cout << "s: " << s << '\n';
	string finish = start;
	reverse(finish.begin(), finish.end());
	int n = s.length();
	long long pref[n + 1], suff[n + 1], curr;
	pref[0] = 0;
	curr = GEN;
	for (int i = 0; i < n; i++) {
		pref[i + 1] = (pref[i] + ((long long)(s[i] - 'a') * curr)) % MOD;
		curr *= GEN;
		curr %= MOD;
	}
	reverse(s.begin(), s.end());
	suff[0] = 0;
	curr = GEN;
	for (int i = 0; i < n; i++) {
		suff[i + 1] = (suff[i] + ((long long)(s[i] - 'a') * curr)) % MOD;
		curr *= GEN;
		curr %= MOD;
	}
	// cout << "\nPREF\n";
	// for (int i = 0; i <= n; i++) {
		// cout << pref[i] << ' ';
	// }
	// cout << "\n\n";
	// cout << "\nSUFF\n";
	// for (int i = 0; i <= n; i++) {
		// cout << suff[i] << ' ';
	// }
	// cout << "\n\n";
	auto pquery = [&pref](int l, int r) {
		return (pref[r] - pref[l - 1] + MOD) % MOD;
	};
	auto squery = [&suff](int l, int r) {
		return (suff[r] - suff[l - 1] + MOD) % MOD;
	};
	int bestp = -1, bests = -1;
	for (int r = 1; r <= n; r++) {
		if ((pquery(1, r) * binpow(GEN, n - r)) % MOD == squery(n + 1 - r, n)) {bestp = r;}
	}
	for (int l = n; l >= 1; l--) {
		if (pquery(l, n) == (squery(1, n + 1 - l) * binpow(GEN, l - 1)) % MOD) {bests = l;}
	}
	reverse(s.begin(), s.end());
	string rest = "";
	bool okp = (bestp != -1), oks = (bests != -1);
	if (okp && oks) {
		if (bestp - 1 >= n - bests) {
			for (int i = 1; i <= bestp; i++) {
				rest += s[i - 1];
			}
		}
		else {
			for (int i = bests; i <= n; i++) {
				rest += s[i - 1];
			}
		}
	}
	else if (okp) {
		for (int i = 1; i <= bestp; i++) {
			rest += s[i - 1];
		}
	}
	else if (oks) {
		for (int i = bests; i <= n; i++) {
			rest += s[i - 1];
		}
	}
	if (rest == "") {rest += s[0];}
	cout << start << rest << finish << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}