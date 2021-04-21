#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int v2(int n) {
	for (int i = 0; i < 20; i++) {
		if (n % (1 << i) != 0) {return i - 1;}
	}
}

bool works(int a[], int n, int sum) {
    if (sum & 1) return false;
    int half = sum >> 1;
    vector<bool> ok(half + 1, false);
    ok[0] = true;    
    for (int i = 0; i < n; i++) {
    	for (int j = half; j >= a[i]; j--) {
    		if (ok[j - a[i]]) {
    			ok[j] = true;
    		}
    	}
    }
    return ok[half];
}

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	int mnv2 = MOD, mn, nowv2, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		nowv2 = v2(a[i]);
		if (nowv2 < mnv2) {
			mn = i;
			mnv2 = nowv2;
		}
		sum += a[i];
	}
	if (!works(a, n, sum)) {cout << 0 << endl;}
	else {cout << 1 << endl << mn + 1 << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}