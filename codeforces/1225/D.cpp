#include <bits/stdc++.h>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

vector<int> primes;

bool isPrime(int n) {
	if (n <= 1) {return false;}
    for (int i = 2; i * i <= n; i++) {
    	if (n % i == 0) {return false;}
    }
    return true;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int a;
	map<vector<int>, pair<long long, long long>> mp, mpdiff, mbp, mbdiff;
	for (int _ = 0; _ < n; _++) {
		cin >> a;
		vector<int> v, vr;
		bool nonzero = false;
		
		for (int i : primes) {
			int cnt = 0;
			while (a % i == 0) {
				a /= i;
				cnt++;
			}
			if ((cnt % k) != ((k - (cnt % k)) % k)) {nonzero = true;}
			v.push_back(cnt % k);
			vr.push_back((k - (cnt % k)) % k);
		}
		
		if (a > 1) {
			v.push_back(a);
			vr.push_back(a);
			if (nonzero) {
				mbp[v].first++;
				mbp[vr].second++;
			}
			else {
				mbdiff[v].first++;
			}
		}
		else {
			if (nonzero) {
				mp[v].first++;
				mp[vr].second++;
			}
			else {
				mpdiff[v].first++;
			}
		}
	}
	long long res = 0, resb = 0;
	for (auto x : mp) {
		res += ((x.second.first) * (x.second.second));
	}
	res /= 2;
	for (auto x : mpdiff) {
		res += ((x.second.first) * (x.second.first - 1)) / 2;
	}
	if (k == 2) {
		for (auto x : mbp) {
			resb += ((x.second.first) * (x.second.second));
		}
		resb /= 2;
		for (auto x : mbdiff) {
			resb += ((x.second.first) * (x.second.first - 1)) / 2;
		}
	}
	cout << res + resb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    for (int i = 1; i * i <= MAX; i++) {
    	if (isPrime(i)) {
    		primes.push_back(i);
    	}
    }
    solve();
}