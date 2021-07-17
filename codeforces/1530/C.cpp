#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7], b[n + 7];
	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
	    cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int suma = 0, sumb = 0;
	for (int i = n / 4; i < n; i++) {
	    suma += a[i];
	    sumb += b[i];
	}
	if (suma >= sumb) {cout << 0 << endl; return;}
	int pt = n / 4, ptb = n / 4 - 1, cnt = 0;
	while (true) {
	    cnt++;
	    suma += 100;
	    if (ptb >= 0 && (n + cnt) % 4 != 0) {
	        sumb += b[ptb];
	        ptb--;
	    }
	    if ((n + cnt) % 4 == 0) {
	        if (pt < n) {suma -= a[pt]; pt++;}
	        else {suma -= 100;}
	    }
	    
	    if (suma >= sumb) {cout << cnt << endl; return;}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}