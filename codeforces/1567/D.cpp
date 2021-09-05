#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long split(long long n) {
	long long pow10 = 1;
	while (pow10 <= n) {
		if (pow10 == n) {return pow10 / 10;}
		pow10 *= 10;
	}
	return pow10 / 10;
}

bool isPow10(long long n) {
	long long pow10 = 1;
	while (pow10 <= n) {
		if (pow10 == n) {return true;}
		pow10 *= 10;
	}
	return false;
}

void solve() {
	long long s;
	int n;
	cin >> s >> n;
	vector<long long> curr;
	curr.push_back(s);
	for (int mv = 0; mv < n - 1; mv++) {
		long long x = -1;
		for (int i = 0; i < curr.size(); i++) {
			if (!isPow10(curr[i])) {
				x = curr[i]; 
				curr.erase(curr.begin() + i); 
				break;
			}
		}
		if (x == -1) {
			long long mn = 1000000000007ll;
			for (int i = 0; i < curr.size(); i++) {
				if (curr[i] != 1) {
					mn = min(mn, curr[i]);
				}
			}
			for (int i = 0; i < curr.size(); i++) {
				if (curr[i] == mn) {
					x = curr[i]; 
					curr.erase(curr.begin() + i); 
					break;
				}
			}
		}
		curr.push_back(split(x));
		curr.push_back(x - split(x));
	}
	for (auto i : curr) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}