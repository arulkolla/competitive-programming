#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	if (n < 64) {
		if (k > (1LL << (n - 1))) {cout << -1 << endl; return;}
	}
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	k--;
	string bits = bitset<64>(k).to_string(), s;
	if (64 - n + 1 >= 0) {
	    s = bits.substr(bits.size() - n + 1);
	}
	else {
		for (int i = n - 1; i > bits.size(); i--) {
			s += '0';
		}
		s += bits;
	}
	int val = 0, init = 0;
	for (int i = 0; i < s.size(); i++) {
	    if (s[i] == '0') {
	    	reverse(a + init, a + init + val + 1); 
	    	init += val + 1; val = 0;
	    }
	    else {val++;}
	}
	reverse(a + init, a + init + val + 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}