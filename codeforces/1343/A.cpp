#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int curr = 4;
    while (n % (curr - 1) != 0) {
        curr *= 2;
    }
    cout << n/(curr-1);
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
    //solve();
}