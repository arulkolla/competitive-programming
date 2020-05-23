#include <algorithm>
#include <cassert>
#include <cmath>
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

void solve() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return;
    }
    switch (n % 4) {
        case 0:
            cout << 6;
            break;
        case 1:
            cout << 8;
            break;
        case 2:
            cout << 4;
            break;
        case 3:
            cout << 2;
            break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}