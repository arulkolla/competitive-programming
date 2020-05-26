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
    int n, m;
    cin >> n >> m;
    if ((n * m) % 2) {
        cout << (n * m)/2 + 1;
    }
    else {
        cout << (n * m)/2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    //solve();
}