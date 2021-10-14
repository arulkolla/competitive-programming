#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int res[7] = {}, lost[6] = {4, 8, 15, 16, 23, 42};
map<int, pair<int, int> > mp;

void query(int x, int y, int z) {
	cout << "? " << x << ' ' << y << endl;
	int r1;
	cin >> r1;
	cout << "? " << y << ' ' << z << endl;
	int r2;
	cin >> r2;
	vector<int> v1, v2;
	v1.push_back(mp[r1].first); v1.push_back(mp[r1].second);
	v2.push_back(mp[r2].first); v2.push_back(mp[r2].second);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (v1[i] == v2[j]) {res[y] = v1[i]; res[x] = v1[!i]; res[z] = v2[!j];}
		}
	}
}

void solve() {
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			mp[lost[i] * lost[j]] = make_pair(lost[i], lost[j]);
		}
	}
	query(1, 2, 3);
	query(4, 5, 6);
	cout << "! ";
	for (int i = 1; i <= 6; i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}