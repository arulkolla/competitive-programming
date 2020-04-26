#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    unsigned long long x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;
    if (b >= 2*a) {
        if (x < y) {
            cout << a*(y-x)+2*a*x;
        }
        else if (x > y) {
            cout << a*(x-y)+2*a*y;
        }
        else {
            cout << a*(x+y);
        }
    }
    else {
        if (x < y) {
            cout << a*(y-x)+b*x;
        }
        else if (x > y) {
            cout << a*(x-y)+b*y;
        }
        else {
            cout << b*y;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
//    solve();
}
