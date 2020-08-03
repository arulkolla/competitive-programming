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

const int MAX = 150007;
const int MOD = 1000000007;

void solve() {
    int n;
    long double d;
    cin >> n >> d;
    long double a, b;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (sqrt(a*a + b*b) <= d) {res++;}
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("rental.in", "r", stdin); freopen("rental.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
