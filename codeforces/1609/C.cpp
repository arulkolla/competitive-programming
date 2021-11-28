#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool isPrime(int n) {
	if (n <= 1) {return false;}
    for (int i = 2; i * i <= n; i++) {
    	if (n % i == 0) {return false;}
    }
    return true;
}

long long f(vector<int> v) {
	int n = v.size();
	vector<int> ind;
	int prv = 0, nxt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 2) {ind.push_back(i);}
	}
	long long res = 0;
	for (int i : ind) {
		int l = i, r = i;
		while (l >= 1 && v[l - 1] == 1) {l--;}
		while (r < n - 1 && v[r + 1] == 1) {r++;}
		res += (long long)(i - l + 1) * (long long)(r - i + 1) - 1ll;
	}
	return res;
}

void solve() {
	int n, e;
	cin >> n >> e;
	int a[n + 7];
	vector<int> v[e + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (isPrime(a[i])) {v[i % e].push_back(2);}
		else if (a[i] == 1) {v[i % e].push_back(1);}
		else {v[i % e].push_back(0);}
	}
	long long cnt = 0;
	for (int i = 0; i < e; i++) {
		cnt += f(v[i]);
	}
	cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}