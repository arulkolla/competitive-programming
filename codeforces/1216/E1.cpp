#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long a[MAX], psum[MAX];

void solve() {
	int q;
	cin >> q;
	auto k = upper_bound(psum, psum + MAX, q);
	k--;
	long long val = k - psum, dist = (q - *k);
	if (dist == 0) {dist = *k; k--; dist -= *k;}
	for (int i = 1; i <= val + 1; i++) {
		string s = to_string(i);
		if (dist > s.length()) {dist -= s.length();}
		else {cout << s[dist - 1] << '\n'; return;}
	}
	assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a[1] = 1;
    psum[1] = 1;
    for (int i = 2; i < MAX; i++) {
    	a[i] = a[i - 1];
    	if (i < 10) {a[i] += 1;}
    	else if (i < 100) {a[i] += 2;}
    	else if (i < 1000) {a[i] += 3;}
    	else if (i < 10000) {a[i] += 4;}
    	else if (i < 100000) {a[i] += 5;}
    	else if (i < 1000000) {a[i] += 6;}
    	else {a[i] += 7;}
    	psum[i] = psum[i - 1] + a[i];
    }
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}