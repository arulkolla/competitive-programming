#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

set<long long> st, st2;

void f(long long n, long long num, int a, int b) {
	if (num > 0 && num <= n) {st.insert(num);}
	if (num >= n) {return;}
	if (num * 10 + a > num) {f(n, num * 10 + a, a, b);}
	f(n, num * 10 + b, a, b);
}

void f2(long long n, long long num, int a) {
	if (num > 0 && num <= n) {st2.insert(num);}
	if (num >= n) {return;}
	f2(n, num * 10 + a, a);
}

void solve() {
	long long x;
	int k;
	cin >> x >> k;
	if (k == 1) {
		string s = to_string(x);
		cout << *st2.lower_bound(x) << endl;
	}
	else {
		cout << *st.lower_bound(x) << endl;	
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 9; i++) {
    	f2(1000000000000ll, 0ll, i);
    }
    for (int i = 0; i <= 9; i++) {
    	for (int j = i + 1; j <= 9; j++) {
    		f(1000000000000ll, 0ll, i, j);
    	}
    }	
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}