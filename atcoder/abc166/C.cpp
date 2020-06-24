#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> edges[MAX];
    int heights[MAX];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int ed, ef;
    for (int i = 0; i < m; i++) {
        cin >> ed >> ef;
        ed--; ef--;
        edges[ed].push_back(ef);
        edges[ef].push_back(ed);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j : edges[i]) {
            if (heights[j] >= heights[i]) {
                good = false; break;
            }
        }
        if (good) {
            res++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}