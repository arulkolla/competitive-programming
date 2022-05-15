#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<long long> conv(long long n, int b) {
    vector<long long> v;
    while (n != 0) {
        long long i = n % b;
        n /= b;
        if (i < 0) {
            i += (-b);
            n++;
        }
        v.push_back(i);
    }
    return v;
}

void solve() {
	long long p; int k;
	cin >> p >> k;
	vector<long long> v = conv(p, -k);
	cout << v.size() << '\n';
	for (auto i : v) {
		cout << i << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}