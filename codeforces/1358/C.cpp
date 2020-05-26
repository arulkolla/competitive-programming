#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 100009;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    unsigned long long xDiff = x2 - x1, yDiff = y2 - y1;
    if (xDiff == 0 || yDiff == 0) {
        cout << 1;
        return;
    }
    cout << xDiff * yDiff + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    //solve();
}
