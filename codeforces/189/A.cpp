#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int maxD = -1;
    for (int i = 0; i <= n/a; i++) {
        for (int j = 0; j <= n/b; j++) {
            if ((n - i*a - j*b) % c == 0 && (n - i*a - j*b)>=0) {maxD = max(maxD, i+j+(n - i*a - j*b)/c);}
        }
    }
    cout << maxD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        solve();
//        cout << endl;
//    }
    solve();
}