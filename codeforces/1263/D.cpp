#include <algorithm>
#include <cassert>
#include <cmath>
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

const int MAX = 222222;

vector<int> g[MAX];
char used[MAX];

void addEdge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

void dfs(int a) {
    used[a] = 1;
    for (int i : g[a]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c : s) {
            addEdge(i, n + c - 'a');
        }
    }
    int ans = 0;
    for (int i = n; i < n + 26; i++) {
        if (!g[i].empty() && !used[i]) {
            dfs(i); ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}