#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, d, new_a, work;
    cin >> n >> d;
    int a;
    cin >> a;
    for(int i = 1; i < n; i++){
        cin >> new_a;
        work = min(new_a, d/i);
        a += work;
        d -= work * i;
    }
    cout << a;
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