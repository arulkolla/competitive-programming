#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct pt {
	int x, y, z, ind;
	bool operator <(pt other) const {
		if (z != other.z) {return z < other.z;}
		if (x != other.x) {return x < other.x;}
		if (y != other.y) {return y < other.y;}
		return ind < other.ind;
	}
};

void solve() {
	int n;
	cin >> n;
	int xval, yval, zval;
	vector<pt> points1;
	for (int i = 1; i <= n; i++) {
		cin >> xval >> yval >> zval;
		points1.push_back(pt({xval, yval, zval, i}));
	}
	sort(points1.begin(), points1.end());
	vector<pt> points2;
	for (int i = 0; i < points1.size(); i += 2) {
		if (i + 1 < points1.size() && points1[i].z == points1[i + 1].z && points1[i].x == points1[i + 1].x) {
			cout << points1[i].ind << ' ' << points1[i + 1].ind << endl;
		}
		else {
			points2.push_back(points1[i]);
			i--;
		}
	}
	if (points2.size() % 2 == 1) {
		points2.push_back(points1[points1.size() - 1]);
	}
	assert(points2.size() % 2 == 0);
	vector<pt> points3;
	for (int i = 0; i < points2.size(); i += 2) {
		if (i + 1 < points2.size() && points2[i].z == points2[i + 1].z) {
			cout << points2[i].ind << ' ' << points2[i + 1].ind << endl;
		}
		else {
			points3.push_back(points2[i]);
			i--;
		}
	}
	if (points3.size() % 2 == 1) {
		points3.push_back(points2[points2.size() - 1]);
	}
	assert(points3.size() % 2 == 0);
	for (int i = 0; i < points3.size(); i += 2) {
		cout << points3[i].ind << ' ' << points3[i + 1].ind << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}