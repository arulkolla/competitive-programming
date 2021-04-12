#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int curr = 1, now = 0;
	string s;
	for (int i = 2 * k - 1; i >= 0; i -= 2) {
	    for (int j = 0; j < i; j++) {
	        if (j % 2 == 1) {s += ('a' + now);}
	        else {s += ('a' + (now + j / 2));}
	    }
	    now++;
	}
	for (int i = 0; i < n; i++) {
	    cout << s[i % (k * k)];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}