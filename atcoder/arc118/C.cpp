#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(6);
	v.push_back(10);
	v.push_back(15);
	for (int i = 16; i <= 10000; i++) {
		if (i % 6 == 0 || i % 10 == 0 || i % 15 == 0) {
			v.push_back(i);
		}
		if (v.size() == n) {break;}
	}
	for (int i : v) {
		cout << i << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}