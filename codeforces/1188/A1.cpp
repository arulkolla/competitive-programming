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

const int MAX = 100009;

vector<int> g[MAX];

void addEdge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

void solve() {
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        addEdge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 2) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
