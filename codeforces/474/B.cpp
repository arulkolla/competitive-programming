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

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l)/2;
        if (arr[m - 1] < x && x <= arr[m]) {
            //x lies between the two ranges
            return m;
        }
        else if (arr[m] < x) {
            //m is too small
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int a[100001], temp, sum = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        sum += temp;
        a[i] = sum;
    }
    int m;
    cin >> m;
    int q;
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << binarySearch(a, 0, n, q) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}