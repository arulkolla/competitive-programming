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
    int a, b;
    cin >> a >> b;
    int arr[3] = {0};
    for (int i = 1; i <= 6; i++) {
        if (abs(a - i) < abs(b - i)) {arr[0]++;}
        else if (abs(a - i) > abs(b - i)) {arr[2]++;}
        else {arr[1]++;}
    }
    for (int i : arr) {
        cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}