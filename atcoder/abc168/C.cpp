#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    long double angle = abs(0.5 * (60 * h - 11 * m));
    if (angle > 180) {angle = 360 - angle;}
    angle *= 3.14159265358979323846/180.0;
    cout << fixed << setprecision(20) << sqrt(a * a + b * b - 2 * a * b * cos(angle));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
