#include <algorithm>
#include <cassert>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    std::sort(a.begin(), a.end());
    pair<int, int> now = make_pair(0, 0);
    string ans;
    bool good = true;
    for (int i = 0; i < n; ++i) {
        int xDiff = a[i].first - now.first;
        int yDiff = a[i].second - now.second;
        if (xDiff < 0 || yDiff < 0) {
            cout << "NO";
            good = false;
            break;
        }
        ans += string(xDiff, 'R');
        ans += string(yDiff, 'U');
        now = a[i];
    }

    if (good) {cout << "YES" << endl << ans;}
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