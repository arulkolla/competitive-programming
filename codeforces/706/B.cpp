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

int binarySearchCount(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    int count = 0;

    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] <= key) {
            count = mid + 1;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x+n);
    int q;
    cin >> q;
    int mx;
    for (int i = 0; i < q; i++) {
        cin >> mx;
        cout << binarySearchCount(x, n, mx) << endl;
    }
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