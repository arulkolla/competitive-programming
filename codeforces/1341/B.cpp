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
    int k, n;
    cin >> n >> k;
    int a[200005], peaks[200005];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
        peaks[i] = (a[i] > a[i-1] && a[i] > a[i+1]);
    }
    for (int i = 1; i <= n; i++) {
        peaks[i] += peaks[i-1];
    }
    int max = -1, index = 0, i = 1;
    for (int j = k; j <= n; j++) {
        if(peaks[j-1]-peaks[i]>max) {index = i, max = peaks[j-1] - peaks[i];}
        i++;
    }
    cout << max+1 << " " << index;
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