#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int query(vector<int> v) {
	cout << "? ";
	assert(v.size() == 100);
	for (int i = 0; i < 100; i++) {
		cout << v[i];
		if (i != 99) {cout << ' ';}
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void answer(int n) {
	cout << "! " << n << endl;
}

void solve() {
	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		v.push_back(i);
	}
	int res = query(v), ans = 0;
	ans += (res / 128) * 128;
	v.clear();
	for (int i = 1; i <= 100; i++) {
		v.push_back(128 * i);
	}
	res = query(v);
	ans += res % 128;
	answer(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}