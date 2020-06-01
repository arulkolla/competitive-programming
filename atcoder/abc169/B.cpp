#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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
    int n;
    cin >> n;
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        long double num;
        cin >> num;
        if (num == 0) {
            res = 0;
            break;
        }
        else if (num > ((long double) 1e18 / res)) {
            res = -1;
        }
        else {
            res *= num;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
