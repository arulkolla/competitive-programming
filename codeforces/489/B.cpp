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
    int b, g, res = 0;
    cin >> b;
    int boys[b];
    for (int i = 0; i < b; i++) {
        cin >> boys[i];
    }
    cin >> g;
    int girls[g];
    for (int i = 0; i < g; i++) {
        cin >> girls[i];
    }
    sort(boys, boys + b);
    sort(girls, girls + g);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < g; j++) {
            if (abs(boys[i] - girls[j]) <= 1) {
                girls[j] = 1000;
                res++;
                break;
            }
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//        cout << endl;
//    }
    solve();
}