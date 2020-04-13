#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int q[9];
    for (int & i : q) {
        cin >> i;
    }
    int a[9] = {100000000, 10000, 1, 10000000, 1000, 100, 1000000, 100000, 10};
    for (int i = 0; i < 9; i++) {
        if ((q[i] / a[i]) % 10 == 9) {q[i] -= a[i];}
        else {q[i] += a[i];}
    }
    for (int i = 0; i < 9; i++) {
        cout << q[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
