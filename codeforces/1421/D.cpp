
// Problem: D. Hexagons
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long c1, c2, c3, c4, c5, c6;
long long x, y;
	
long long dist(long long k) {
	long long res = 0;
	if (k >= x) {
		res += c3 * abs(k - x);
	}
	else {
		res += c6 * abs(k - x);
	}
	if (k >= y) {
		res += c5 * abs(k - y);
	}
	else {
		res += c2 * abs(k - y);
	}
	return res;
}

void solve() {
	cin >> y >> x;
	long long a[6];
	for (int i = 0; i < 6; i++) {cin >> a[i];}
	long long v[6];
	for (int i = 0; i < 6; i++) {v[i] = min(a[i],a[(i+1)%6]+a[(i-1+6)%6]);}
	if (x >= 0 && y >= 0) {
		cout << min(x,y) * v[0] + (x-min(x,y)) * v[1] + (y-min(x,y)) * v[5];
	}
	else if(x<=0 && y<=0){
		x = -x;
		y = -y;
		cout << min(x,y)*v[3] + (x-min(x,y))*v[4] + (y-min(x,y))*v[2]; 
	}
	else if(x>0){
		y = -y;
		cout << x*v[1] + y*v[2];
	}
	else{
		x = -x;
		cout << x*v[4] + y*v[5];
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}