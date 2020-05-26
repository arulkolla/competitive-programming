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

const int MAX = 33333;

void solve() {
    int n, t;
    cin >> n >> t;
    int a[MAX] = {0};
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    int current = 1;
    while (current < n) {
        current += a[current];
        if (current == t) {cout << "YES"; return;}
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}