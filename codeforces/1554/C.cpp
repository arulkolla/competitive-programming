#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, m;
	cin >> n >> m;
	if (n > m) {
		cout << 0 << endl;
		return;
	}
	m++;
	
	bitset<32> ns(n), ms(m);
	long long res = 0;
	for (int i = 31; i >= 0; i--) {
		if (ns[i] == 0 && ms[i] == 1) {
			res |= (1 << i);
		}
		else if (ns[i] && !ms[i]) {break;}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}