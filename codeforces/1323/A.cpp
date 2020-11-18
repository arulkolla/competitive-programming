#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int a[n + 7];
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2) {odd.push_back(i + 1);}
        else {even.push_back(i + 1);}
    }
    if (n == 1 && a[0] % 2) {cout << -1 << endl;}
    else {
        if (n == 1) {cout << 1 << endl << 1 << endl;}
        else {
            if (even.empty()) {cout << 2 << endl << odd[0] << " " << odd[1] << endl;}
            else {cout << 1 << endl << even[0] << endl;}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("sample.in", "r", stdin); freopen("sample.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}