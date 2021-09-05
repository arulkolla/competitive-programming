#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 200 * 1000 + 13;

typedef long long li;

int n, m;
int a[N], b[N];

struct node{
	int pr, su, len;
	li ans;
};

node t[4 * N];

node merge(const node &a, const node &b){
	node c;
	c.pr = a.pr + (a.pr == a.len ? b.pr : 0);
	c.su = b.su + (b.su == b.len ? a.su : 0);
	c.ans = a.ans + b.ans + a.su * 1ll * b.pr;
	c.len = a.len + b.len;
	return c;
}

void build(int v, int l, int r){
	if (l == r - 1){
		t[v] = {int(b[l] >= 0), int(b[l] >= 0), 1, li(b[l] >= 0)};
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, int val){
	if (l == r - 1){
		t[v] = {val, val, 1, li(val)};
		return;
	}
	int m = (l + r) / 2;
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int l, int r, int L, int R){
	if (L >= R)
		return {0, 0, 0, 0ll};
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	return merge(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
}

int main() {
	scanf("%d%d", &n, &m);
	forn(i, n) scanf("%d", &a[i]);
	
	if (n == 1){
		forn(i, m){
			int t, x, y;
			scanf("%d%d%d", &t, &x, &y);
			if (t == 2){
				puts("1");
			}
		}
		return 0;
	}
	
	forn(i, n - 1) b[i] = a[i + 1] - a[i];
	build(1, 0, n - 1);
	forn(i, m){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1){
			--x;
			a[x] = y;
			if (x > 0)
				upd(1, 0, n - 1, x - 1, a[x] >= a[x - 1]);
			if (x + 1 < n)
				upd(1, 0, n - 1, x, a[x + 1] >= a[x]);
		}
		else{
			--x, --y;
			li ans = get(1, 0, n - 1, x, y).ans;
			printf("%lld\n", ans + y - x + 1);
		}
	}
}