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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;
    long long curr = 0;
    for (long long i = 0; i < 1000000; i++) {
        curr = ((curr * 10) % n + 7) % n;
        if (curr % n == 0) {cout << i + 1; return;}
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("rental.in", "r", stdin); freopen("rental.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
