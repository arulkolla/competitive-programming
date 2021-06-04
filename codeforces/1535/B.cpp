#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int gcd(int a, int b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	int a;
	vector<int> odds, evens, res;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 0) {evens.push_back(a);}
		else {odds.push_back(a);}
	}
	for (int i : evens) {res.push_back(i);}
	for (int i : odds) {res.push_back(i);}
	int cnt = 0;
	for (int i = 0; i < res.size(); i++) {
		for (int j = i + 1; j < res.size(); j++) {
			if (gcd(res[i], 2 * res[j]) > 1) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}